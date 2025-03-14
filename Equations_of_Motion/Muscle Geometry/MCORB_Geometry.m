% Načtení parametrů
run('UpperLimbExo_Parameters.m');  % Načteme soubor s parametry
sval_name = 'M_CORB'; % Uložíme název jako string
sval = M_CORB; % Načteme odpovídající strukturu

% Dynamické generování názvů souborů
filename_LM = sprintf('%s_LM.m', sval_name);
filename_vM = sprintf('%s_vM.m', sval_name);
filename_Q = sprintf('%s_Q.m', sval_name);

    % Načtení požadovaných parametrů
    struct_params = {'x1B', 'y1B', 'x2A', 'y2A'};  % Bod na humeru v lokálním systému 2
    struct_values = cellfun(@(v) getfield(sval, v), struct_params, 'UniformOutput', false);
    global_params = {'L2'};
    global_values = cellfun(@(v) evalin('base', v), global_params, 'UniformOutput', false);
    required_params = [struct_params, global_params];  
    vars_values = [struct_values, global_values];


% Symbolicke promenne
    % Převod na symbolické proměnné a hodnoty
    syms_list = sym(required_params);  
    vals_list = [vars_values{:}];  
    syms(required_params{:})  
    
    % Definice symbolických proměnných
    syms fi12 fi12_dot real  

%% GEOMETRIE
    % Převod bodu z lokálního systému 2 do globálního systému
    R2 = [cos(fi12), -sin(fi12); sin(fi12), cos(fi12)];
    p1A = R2 * [x2A; y2A];

    p1B = [x1B; y1B];

    % Výpočet délky svalu
    LM_total_sym = norm(p1B - p1A);
    LM_total_sym = subs(LM_total_sym, syms_list, vals_list);

    % Vypocet rychlosti dL(fi(t))/dt = dL/dfi*dfi/dt
    vM_total_sym = diff(LM_total_sym, fi12) * fi12_dot;

    % Výpočet momentových ramen
    M12_total = -diff(vM_total_sym, fi12_dot);
    M13_total = 0;

%% Uložení numerických funkcí přímo do `.m` souborů
matlabFunction(LM_total_sym, 'Vars', [fi12], 'File', filename_LM);
matlabFunction(vM_total_sym, 'Vars', [fi12, fi12_dot], 'File', filename_vM);
matlabFunction([M12_total; M13_total], 'Vars', [fi12], 'File', filename_Q);

fprintf('✅ Funkce byly uloženy jako "%s", "%s" a "%s".\n', filename_LM, filename_vM, filename_Q);

