function out1 = M_CORB_Q(fi12)
%M_CORB_Q
%    OUT1 = M_CORB_Q(FI12)

%    This function was generated by the Symbolic Math Toolbox version 24.2.
%    14-May-2025 15:34:07

t2 = cos(fi12);
t3 = sin(fi12);
t4 = t2.*1.76e-3;
t5 = t3.*1.76e-3;
t6 = t2.*1.6485e-1;
t7 = t3.*1.6485e-1;
t8 = -t6;
t9 = t4+t7-8.06e-3;
t10 = abs(t9);
t11 = t5+t8+3.467e-2;
t12 = abs(t11);
out1 = [(1.0./sqrt(t10.^2+t12.^2).*(t10.*sign(t9).*(t5+t8).*2.0-t12.*sign(t11).*(t4+t7).*2.0))./2.0;0.0];
end
