function Points = Muscle_Points_ALL(q)

    fi12 = q(1);
    fi13 = q(2);

    % Formát: název, funkce, počet vstupních argumentů
    Muscles = {
        'M_CORB',       @M_CORB_points,      1;
        'M_TMAJ',       @M_TMAJ_points,      1;
        'M_DELT',       @M_DELT_points,      1;
        'M_TRIPB_CMED', @M_TRIPB_CMED_points, 2;
        'M_TRIPB_CLAT', @M_TRIPB_CLAT_points, 2;
        'M_TRIPB_CLONG',@M_TRIPB_CLONG_points,2;
        'M_BICB',       @M_BICB_points,      2;
        'M_BRACH',      @M_BRACH_points,     2;
    };

    n_muscles = size(Muscles, 1);
    n_points = 3;  % A, B, W
    dim = 2;       % x, y

    Points = NaN(n_muscles, dim, n_points);  % Výstupní pole

    for i = 1:n_muscles
        func = Muscles{i,2};
        n_input = Muscles{i,3};

        % Výběr vstupních proměnných
        switch n_input
            case 1
                [pA, pB, pW] = func(fi12);
            case 2
                [pA, pB, pW] = func(fi12, fi13);
        end

        % Uložení výstupních bodů do pole
        Points(i,:,1) = pA(:);
        Points(i,:,2) = pB(:);
        Points(i,:,3) = pW(:);
    end
end
