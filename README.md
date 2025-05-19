# Upper Extremity Model - MATLAB/Simulink

This repository provides the upper limb model developed in MATLAB/Simulink as part of paper "Optimizing Upper Limb Exoskeleton Efficiency: A Conceptual Approach Using Active-Passive Elements for Reduced Energy Demand". It includes all necessary files to run simulations of the upper limb dynamics.

## Repository Structure

```
📂 Upper-Extremity-Model
├── Data_OpenSim/                     # Exported data from OpenSim
├── Muscle Geometry/                  # Muscle geometry equations
├── Optimization/                     # Optimization code for Computed Muscle Control
├── Parameters_OpenSim                # Extracting parameters from exported data from OpenSim
├── UpperLimb_Main.m                  # Adds required directories to MATLAB's path and sets up the environment
├── UpperLimb_planar.slx              # Simulink file of planar upper limb model
└── UpperLimbExo_Parameters.m         # Defines the parameters for the upper limb model
```

## Running the Simulation

1. Open MATLAB.
2. Run `UpperLimb_Main.m` to load parameters and set up the environment.
3. Start the simulation:
   - **Option 1:** Uncomment the `out = sim("UpperLimb_Planar.slx");` command in `UpperLimb_Main.m` and execute the script.
   - **Option 2:** Run the simulation manually from the main Simulink model after executing `UpperLimb_Main.m`.

## Requirements

- MATLAB with Simulink toolbox.
- Ensure all necessary folders with its subfolders are correctly referenced in `UpperLimb_Main.m`.


## Authors
- Jan Krivošej,
- Jakub Švadlena,
- Júlia Bodnárová,
- Matej Daniel,
- Zbyněk Šika


## Contact

For any questions regarding this model, please contact us via email: [jakub.svadlena@fs.cvut.cz](mailto:jakub.svadlena@fs.cvut.cz)

