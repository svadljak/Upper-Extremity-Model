# Upper Extremity Model - MATLAB/Simulink

This repository provides the upper limb model developed in MATLAB/Simulink as part of paper "Optimizing Upper Limb Exoskeleton Efficiency: A Conceptual Approach Using Active-Passive Elements for Reduced Energy Demand". It includes all necessary files to run simulations of the upper limb dynamics.

## Repository Structure

```
📂 Upper-Extremity-Model
├── UpperLimb_Main.m                  # Adds required directories to MATLAB's path and sets up the environment
├── UpperLimbExo_Parameters.m         # Defines the parameters for the upper limb model
├── UpperLimb_models/                # Contains submodels of the upper limb
├── Equations_of_Motion/              # Includes muscle geometry equations used in the simulation and optimization
└── UpperLimb_planar.slx              # Primary Simulink model that loads additional models
```

## Running the Simulation

1. Open MATLAB.
2. Run `UpperLimb_Main.m` to load parameters and set up the environment.
3. Start the simulation:
   - **Option 1:** Uncomment the `simOut = sim("UpperLimb_Planar.slx");` command in `UpperLimb_Main.m` and execute the script.
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

For any questions regarding this model, please contact us on email us via email: [jakub.svadlena@fs.cvut.cz](mailto:jakub.svadlena@fs.cvut.cz)

