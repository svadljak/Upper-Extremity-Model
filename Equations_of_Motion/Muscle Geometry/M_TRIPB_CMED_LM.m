function LM_total_sym = M_TRIPB_CMED_LM(fi12,fi13)
%M_TRIPB_CMED_LM
%    LM_total_sym = M_TRIPB_CMED_LM(FI12,FI13)

%    This function was generated by the Symbolic Math Toolbox version 24.2.
%    05-Mar-2025 23:41:35

t2 = cos(fi12);
t3 = cos(fi13);
t4 = sin(fi12);
t5 = sin(fi13);
t6 = -fi13;
t7 = fi12+t6;
t12 = t3.*2.515027624309392e-2;
t13 = t5.*2.515027624309392e-2;
t17 = t3.*1.667044105283557e-2;
t18 = t5.*1.667044105283557e-2;
t19 = t2.*1.987320944803853e-2;
t20 = t4.*1.987320944803853e-2;
t23 = t2.*1.756515458122541e-1;
t24 = t4.*1.756515458122541e-1;
t8 = cos(t7);
t9 = sin(t7);
t21 = -t18;
t22 = -t19;
t25 = t13+t17;
t31 = t20+t23;
t10 = t9.*1i;
t27 = t12+t21;
t32 = t22+t24;
t11 = -t10;
t28 = abs(t27);
t34 = abs(t32);
t14 = t8+t11;
t30 = t28.^2;
t36 = t34.^2;
t15 = angle(t14);
t16 = t15./5.0e+1;
if ~all(cellfun(@isscalar,{t15}))
    error(message('symbolic:sym:matlabFunction:ConditionsMustBeScalar'));
end
if (t15 < 0.0)
    LM_total_sym = t16+pi./2.5e+1+sqrt(t30+abs(t25).^2)+sqrt(t36+abs(t31).^2);
else
    LM_total_sym = t16+sqrt(t30+abs(t25).^2)+sqrt(t36+abs(t31).^2);
end
end
