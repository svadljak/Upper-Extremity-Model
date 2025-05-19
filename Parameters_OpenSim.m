addpath("Data_OpenSim");

% Načtení dat
filename = '3D_muscle_with_attachment_points.xlsx';
data = readtable(filename);

filename_ratio = 'muscle_tendon_ratio.xlsx';
data_ratio = readtable(filename_ratio);

% --- Uživatelský vstup: seznam svalů, které chceš použít ---
selected_muscles = {"coracobr_2", "ter_maj_3", "delt_scap11", "tric_med_3", "tric_lat_3", "tric_long_3", "bic_l", "brachialis_4"};

csys.scapula_r.rotation = -90*pi/180;
csys.scapula_r.trans.x = -0.023;
csys.scapula_r.trans.y = -0.0439;

csys.humerus_r.rotation = -pi;
csys.humerus_r.trans.x = 0;
csys.humerus_r.trans.y = 0;

csys.ulna_r.rotation = -pi;
csys.ulna_r.trans.x = 0;
csys.ulna_r.trans.y = 0;

csys.radius_r.rotation = -pi;
csys.radius_r.trans.x = 0;
csys.radius_r.trans.y = 0;

% Inicializace výstupních struktur
muscles = struct();

% Pomocná funkce
parseXY = @(str) sscanf(strrep(str, '[',''), '%f', 3);  % přečte [z x y]

% Smyčka přes svaly
for i = 1:length(selected_muscles)
    muscle_name = selected_muscles{i};

    % Indexy bodů
    idx = strcmp(data.muscle_name, muscle_name);
    P1_idx = idx & strcmp(data.path_point_name, muscle_name + "-P1");
    P2_idx = idx & strcmp(data.path_point_name, muscle_name + "-P2");

    if muscle_name == 'bic_l'
        P2_idx = idx & strcmp(data.path_point_name, muscle_name + "-P3");
    end

    % Inicializace struktur
    attachments = struct();
    

    % --- P1 & P2 ---
    P1_location_raw = data.path_point_location{P1_idx};
    P1_body = data.path_point_body{P1_idx};
    vec = parseXY(P1_location_raw);  % [z x y] jako sloupcový vektor
    xy{1} = vec([2 3]);  % x a y

    P2_location_raw = data.path_point_location{P2_idx};
    P2_body = data.path_point_body{P2_idx};
    vec = parseXY(P2_location_raw);  % [z x y]
    xy{2} = vec([2 3]);
    
    
    % vec
    P_body = {P1_body, P2_body};
    P = {'P1', 'P2'};

    for j = 1 : 2
        % Transformace podle těla
        if isfield(csys, P_body{j})
            T = transMatrix(csys.(P_body{j}).rotation, csys.(P_body{j}).trans.x, csys.(P_body{j}).trans.y);
        else
            T = eye(4);
        end

        r_global = [xy{j}; 0; 1];

        r_local = T\r_global;

        attachments.(P{j}).x = r_local(1);
        attachments.(P{j}).y = r_local(2);
        attachments.(P{j}).body = P_body{j};
    end
    % --- Uložení ---
    if strcmp(attachments.P1.body, 'ulna_r') && strcmp(attachments.P2.body, 'scapula_r')
        att_P2 = attachments.P2;
        attachments.P2 = attachments.P1;
        attachments.P1 = att_P2;
    end
    muscles.(muscle_name).attachments = attachments;
end




for i = 1:length(selected_muscles)
    muscle_name = selected_muscles{i};

    % Indexy bodů
    idx = strcmp(data.muscle_name, muscle_name);
    P1_idx = idx & strcmp(data.path_point_name, muscle_name + "-P1");
    
    muscles.(muscle_name).LM0 = sscanf(data.optimal_fiber_length{P1_idx}, '%f');
    muscles.(muscle_name).LTs = sscanf(data.tendon_slack_length{P1_idx}, '%f');
    muscles.(muscle_name).alpha0 = sscanf(data.pennation_angle_at_optimal{P1_idx}, '%f');

    % ratios
    idx_ratio = strcmp(data_ratio.Var1, muscle_name);
    muscles.(muscle_name).ratio = data_ratio.Var2(idx_ratio);
end


% --- Výpočet součtu sil pro základní svaly ---
% Extrakce základních jmen svalů
base_muscles = regexprep(cellstr(selected_muscles), {'(_\d+$)', '(\d+$)'}, '');

% % Unikátní základní svaly
% unique_base = unique(base_muscles);

% Výpočet celkové izometrické síly pro každý základní sval
muscle_force_summary = struct();
for i = 1:length(base_muscles)
    muscle_name = selected_muscles{i};
    base_name = base_muscles{i};

    % Najdi všechna vlákna, která patří tomuto svalu
    fiber_idx = startsWith(data.muscle_name, base_name);

    % Sečti fiber_f0
    AA = data.max_isometric_force(fiber_idx);
    total_FM0 = sum(str2double(strrep(AA,',','.')));

    if muscle_name == 'bic_l'
        muscles.(muscle_name).FM0 = total_FM0/3;
    else
        muscles.(muscle_name).FM0 = total_FM0/2;
    end


end
















function T = transMatrix(phi, x, y)
    S12 = [cos(phi), -sin(phi), 0;
           sin(phi), cos(phi) , 0;
           0       ,    0     , 1];

    u = [x; y; 0];

    T = [S12, u; 0,0,0,1];
end






