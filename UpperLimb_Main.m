addpath(genpath('UpperLimb_models'));
addpath(genpath('Equations_of_Motion'));

% Time sim & sample data
    T_sim = 10;
    T_sampleData = 1e-3;

% Trajectory
        seznamTraj = ["sine_simple", "box"];
        traj = "box";

% Load parameters
    UpperLimbExo_Parameters;




% simOut = sim("UpperLimb_Planar.slx");