function [Q, LMT, vMT] = Muscle_Geometry_ALL(q, qt)
% VSTUPY:
% q  = [fi12; fi13]         % Úhly
% qt = [fi12_dot; fi13_dot] % Rychlosti úhlů
fi12 = q(1);
fi13 = q(2);
fi12_dot = qt(1);
fi13_dot = qt(2);

%% -- GEOMETRIE SVALU --
% MCORB
    LM_1 = M_CORB_LM(fi12);
    vM_1 = M_CORB_vM(fi12, fi12_dot);
    Q1 = M_CORB_Q(fi12);
% MTMAJ
    LM_2 = M_TMAJ_LM(fi12);
    vM_2 = M_TMAJ_vM(fi12, fi12_dot);
    Q2 = M_TMAJ_Q(fi12);
% MDELT
    LM_3 = M_DELT_LM(fi12);
    vM_3 = M_DELT_vM(fi12, fi12_dot);
    Q3 = M_DELT_Q(fi12);
% MTRIPB_CMED
    LM_41 = M_TRIPB_CMED_LM(fi12, fi13);
    vM_41 = M_TRIPB_CMED_vM(fi12, fi13, fi12_dot, fi13_dot);
    Q41 = M_TRIPB_CMED_Q(fi12, fi13);
% MTRIPB_CLAT
    LM_42 = M_TRIPB_CLAT_LM(fi12, fi13);
    vM_42 = M_TRIPB_CLAT_vM(fi12, fi13, fi12_dot, fi13_dot);
    Q42 = M_TRIPB_CLAT_Q(fi12, fi13);
% MTRIPB_CLONG
    LM_43 = M_TRIPB_CLONG_LM(fi12, fi13);
    vM_43 = M_TRIPB_CLONG_vM(fi12, fi13, fi12_dot, fi13_dot);
    Q43 = M_TRIPB_CLONG_Q(fi12, fi13);
% MBICB
    LM_5 = M_BICB_LM(fi12, fi13);
    vM_5 = M_BICB_vM(fi12, fi13, fi12_dot, fi13_dot);
    Q5 = M_BICB_Q(fi12, fi13);
% MBRACH
    LM_6 = M_BRACH_LM(fi12, fi13);
    vM_6 = M_BRACH_vM(fi12, fi13, fi12_dot, fi13_dot);
    Q6 = M_BRACH_Q(fi12, fi13);


% -- OUTPUT --
LMT = [LM_1; LM_2; LM_3; LM_41; LM_42; LM_43; LM_5; LM_6];
vMT = [vM_1; vM_2; vM_3; vM_41; vM_42; vM_43; vM_5; vM_6];
Q = [Q1, Q2, Q3, Q41, Q42, Q43, Q5, Q6];

end