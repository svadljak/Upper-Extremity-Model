Q = rand(2,8);
b = rand(2,1);
Fl = rand(8,1);
Fpe = rand(8,1);
VM = rand(8,1);
LM0 = rand(8,1);
a0 = rand(8,1);
alpha0 = rand(8,1);
FM0 = rand(8,1);

activation = Optimization_ThelenMuscle_codegen_mex(Q, b, Fl, Fpe, VM, LM0, a0, alpha0, FM0);
disp(activation);
