addpath(genpath('Muscle Geometry'));
addpath(genpath('Optimization'));
addpath(genpath('Animations'))

% Funkce geometrie
    % MBICB_Geometry;
    % MBRACH_Geometry;
    % MCORB_Geometry;
    % MDELT_Geometry;
    % MTMAJ_Geometry;
    % MTRIPB_CLAT_Geometry;
    % MTRIPB_CLONG_Geometry;
    % MTRIPB_CMED_Geometry;

clearvars

% Time sim & sample data
    T_sim = 10;
    T_sampleData = 1e-0 ;

% Trajectory
        seznamTraj = ["sine_simple", "box"];
        traj = "sine_simple";

% Load parameters
    UpperLimbExo_Parameters;
   



out = sim("UpperLimb_Planar.slx");
% out = sim("Delky_svalu_Planar.slx");

