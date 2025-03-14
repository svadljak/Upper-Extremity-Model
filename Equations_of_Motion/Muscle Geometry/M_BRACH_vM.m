function vM_total_sym = M_BRACH_vM(fi12,fi13,fi12_dot,fi13_dot)
%M_BRACH_vM
%    vM_total_sym = M_BRACH_vM(FI12,FI13,FI12_DOT,FI13_DOT)

%    This function was generated by the Symbolic Math Toolbox version 24.2.
%    05-Mar-2025 17:48:45

t2 = cos(fi12);
t3 = cos(fi13);
t4 = sin(fi12);
t5 = sin(fi13);
t6 = t3./4.0e+1;
t7 = t5./4.0e+1;
t8 = t2.*1.171e-1;
t9 = t4.*1.171e-1;
t10 = t6+t8;
t11 = t7+t9;
t12 = abs(t10);
t13 = sign(t10);
t14 = abs(t11);
t15 = sign(t11);
t16 = t12.^2;
t17 = t14.^2;
t18 = t16+t17;
t19 = 1.0./sqrt(t18);
vM_total_sym = fi13_dot.*t19.*((t5.*t12.*t13)./2.0e+1-(t3.*t14.*t15)./2.0e+1).*(-1.0./2.0)-(fi12_dot.*t19.*(t4.*t12.*t13.*2.342e-1-t2.*t14.*t15.*2.342e-1))./2.0;
end
