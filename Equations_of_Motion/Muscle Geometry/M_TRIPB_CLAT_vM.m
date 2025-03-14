function vM_total_sym = M_TRIPB_CLAT_vM(fi12,fi13,fi12_dot,fi13_dot)
%M_TRIPB_CLAT_vM
%    vM_total_sym = M_TRIPB_CLAT_vM(FI12,FI13,FI12_DOT,FI13_DOT)

%    This function was generated by the Symbolic Math Toolbox version 24.2.
%    05-Mar-2025 23:41:32

t2 = cos(fi12);
t3 = cos(fi13);
t4 = sin(fi12);
t5 = sin(fi13);
t6 = -fi13;
t7 = fi12+t6;
t13 = t3.*2.515027624309392e-2;
t14 = t5.*2.515027624309392e-2;
t19 = t2.*1.993525035488523e-2;
t20 = t4.*1.993525035488523e-2;
t21 = t3.*1.667044105283557e-2;
t22 = t5.*1.667044105283557e-2;
t24 = t2.*2.47141959798995e-1;
t25 = t4.*2.47141959798995e-1;
t8 = cos(t7);
t9 = sin(t7);
t23 = -t22;
t26 = -t25;
t27 = t14+t21;
t32 = t20+t24;
t10 = t8.^2;
t11 = t9.^2;
t28 = abs(t27);
t29 = t13+t23;
t33 = t19+t26;
t34 = abs(t32);
t12 = 1.0./t10;
t15 = t10+t11;
t30 = abs(t29);
t35 = abs(t33);
t16 = t11.*t12;
t18 = 1.0./t15;
t17 = t16+1.0;
t31 = (t10.*t17.*t18)./5.0e+1;
vM_total_sym = fi13_dot.*(t31+(1.0./sqrt(t28.^2+t30.^2).*(t28.*t29.*sign(t27).*2.0-t27.*t30.*sign(t29).*2.0))./2.0)-fi12_dot.*(t31-(1.0./sqrt(t34.^2+t35.^2).*(t33.*t34.*sign(t32).*2.0-t32.*t35.*sign(t33).*2.0))./2.0);
end
