function out1 = M_CORB_Q(fi12)
%M_CORB_Q
%    OUT1 = M_CORB_Q(FI12)

%    This function was generated by the Symbolic Math Toolbox version 24.2.
%    05-Mar-2025 17:52:43

t2 = cos(fi12);
t3 = sin(fi12);
t4 = abs(t3);
t5 = t2.*1.533e-1;
t6 = t5-2.96e-2;
t7 = abs(t6);
out1 = [1.0./sqrt(t4.^2.*2.350089e-2+t7.^2).*(t2.*t4.*sign(t3).*4.700178e-2-t3.*t7.*sign(t6).*3.066e-1).*(-1.0./2.0);0.0];
end
