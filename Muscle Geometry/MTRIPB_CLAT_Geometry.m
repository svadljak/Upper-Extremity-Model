% Načtení parametrů
run('UpperLimbExo_Parameters.m');  % Načteme soubor s parametry
sval_name = 'M_TRIPB_CLAT'; % Uložíme název jako string
sval = M_TRIPB.CLAT; % Načteme odpovídající strukturu

% Cesty ke složkám
folder_functions = fullfile('Muscle Geometry/Functions');
folder_points = fullfile('Muscle Geometry/Points');

% Dynamické generování názvů souborů
filename_LM = fullfile(folder_functions, sprintf('%s_LM.m', sval_name));
filename_vM = fullfile(folder_functions, sprintf('%s_vM.m', sval_name));
filename_Q =  fullfile(folder_functions, sprintf('%s_Q.m', sval_name));
filename_points = fullfile(folder_points, sprintf('%s_points.m', sval_name));

    % Načtení požadovaných parametrů
    struct_params = {'x3A', 'y3A', 'x2B', 'y2B', 'x2W2', 'y2W2'};  
    struct_values = cellfun(@(v) getfield(sval, v), struct_params, 'UniformOutput', false);
    global_params = {'L2', 'r'};
    global_values = cellfun(@(v) evalin('base', v), global_params, 'UniformOutput', false);
    required_params = [struct_params, global_params];  
    vars_values = [struct_values, global_values];

% Symbolicke promenne
    % Převod na symbolické proměnné a hodnoty
    syms_list = sym(required_params);  
    vals_list = [vars_values{:}];  
    syms(required_params{:}) 

    % Definice symbolických proměnných
    syms fi12 fi13 fi12_dot fi13_dot real  

%% GEOMETRIE
    % Rotační matice ze systému 1
    R1_2 = [cos(fi12), -sin(fi12); sin(fi12), cos(fi12)]; % Rotace z lokálního systému 2 do globálního systému 1
    R1_3 = [cos(fi13), -sin(fi13); sin(fi13), cos(fi13)]; % Rotace z lokálního systému 3 do globálního systému 1

    % Loketní bod (bod E v globálním systému 1)
    p1E = R1_2 * [L2; 0]; % Převod bodu E ze systému 2 do 1

    % Převod bodů do globálního systému 1
    p1A = p1E + R1_3 * [x3A; y3A];  % Bod A v globálním systému
    % p1W3 = p1E + R1_3 * [x3W3; y3W3]; % Bod W3 v globálním systému
    p1W2 = R1_2 * [x2W2; y2W2]; % Bod W2 v globálním systému
    p1B = R1_2 * [x2B; y2B]; % Bod B v globálním systému

    % úhel opásání
        theta = atan2(sin(fi13 - fi12), cos(fi13 - fi12));
        theta = piecewise(theta < 0, theta + 2*pi, theta);

    % Výpočet délky svalu
    % LM_straight = norm(p1A - p1W3) + norm(p1B - p1W2);
    LM_straight = norm(p1B - p1W2);
    LM_circ = r * theta;
    LM_total_sym = LM_straight + LM_circ;

    LM_total_sym = subs(LM_total_sym, syms_list, vals_list);

    % Vypocet rychlosti dL(fi(t))/dt = dL/dfi*dfi/dt
    vM_total_sym = diff(LM_total_sym, fi12) * fi12_dot + diff(LM_total_sym, fi13) * fi13_dot;
    
    % Výpočet momentových ramen
    M12_total = -diff(vM_total_sym, fi12_dot);
    M13_total = -diff(vM_total_sym, fi13_dot);

%% Uložení numerických funkcí přímo do `.m` souborů
matlabFunction(LM_total_sym, 'Vars', [fi12, fi13], 'File', filename_LM);
matlabFunction(vM_total_sym, 'Vars', [fi12, fi13, fi12_dot, fi13_dot], 'File', filename_vM);
matlabFunction([M12_total; M13_total], 'Vars', [fi12, fi13], 'File', filename_Q);

fprintf('✅ Funkce byly uloženy jako:\n   - %s\n   - %s\n   - %s\n', filename_LM, filename_vM, filename_Q);


% Substituce do p1A a p1B
p1A_subs = subs(p1A, syms_list, vals_list);
p1B_subs = subs(p1B, syms_list, vals_list);
p1W_subs = subs(p1W2, syms_list, vals_list);

matlabFunction(p1A_subs, p1B_subs, p1W_subs, 'Vars', [fi12, fi13], 'File', filename_points);
fprintf('📍 Souřadnice bodů byly uloženy jako "%s".\n', filename_points);