function vM_total_sym = M_TRIPB_CLONG_vM(fi12,fi13,fi12_dot,fi13_dot)
%M_TRIPB_CLONG_vM
%    vM_total_sym = M_TRIPB_CLONG_vM(FI12,FI13,FI12_DOT,FI13_DOT)

%    This function was generated by the Symbolic Math Toolbox version 24.2.
%    14-May-2025 15:34:09

t2 = cos(fi12);
t3 = sin(fi12);
t4 = -fi13;
t5 = fi12+t4;
t11 = t2.*1.603e-2;
t12 = t2.*1.611e-2;
t13 = t3.*1.603e-2;
t14 = t3.*1.611e-2;
t6 = cos(t5);
t7 = sin(t5);
t15 = -t13;
t20 = t11+t14;
t8 = t6.^2;
t9 = t7.^2;
t21 = t12+t15;
t25 = t20+2.9e+1./1.0e+2;
t10 = 1.0./t8;
t16 = t8+t9;
t22 = abs(t21);
t23 = sign(t21);
t26 = t25.^2;
t27 = t21.*t25.*2.0;
t17 = t9.*t10;
t19 = 1.0./t16;
t24 = t22.^2;
t38 = t20.*t22.*t23.*2.0;
t18 = t17+1.0;
t28 = t24+t26;
t39 = -t38;
t29 = 1.0./t28;
t30 = 1.0./sqrt(t28);
t48 = t27+t39;
t31 = t30.^3;
t32 = t30./5.0e+1;
t33 = t29./2.5e+3;
t40 = t21.*t30;
t41 = t25.*t30;
t42 = t26.*t29;
t34 = acos(t32);
t35 = -t33;
t43 = acos(t41);
t45 = -t42;
t69 = (t25.*t31.*t48)./2.0;
t36 = t35+1.0;
t44 = conj(t43);
t46 = t45+1.0;
t49 = t34+t43;
t70 = -t69;
t37 = 1.0./sqrt(t36);
t47 = 1.0./sqrt(t46);
t50 = t34+t44;
t51 = cos(t49);
t52 = sin(t49);
t73 = t40+t70;
t53 = cos(t50);
t54 = sin(t50);
t55 = t51./5.0e+1;
t57 = (t2.*t52)./5.0e+1;
t58 = (t3.*t52)./5.0e+1;
t71 = (t31.*t37.*t48)./1.0e+2;
t80 = t47.*t73;
t56 = t53./5.0e+1;
t59 = (t2.*t54)./5.0e+1;
t60 = (t3.*t54)./5.0e+1;
t61 = t55-2.9e+1./1.0e+2;
t62 = t56-2.9e+1./1.0e+2;
t63 = t2.*t61;
t64 = t3.*t61;
t65 = t2.*t62;
t66 = t3.*t62;
t67 = -t63;
t74 = t57+t64-1.611e-2;
t68 = -t65;
t75 = t58+t67+1.603e-2;
t76 = abs(t74);
t78 = t59+t66-1.611e-2;
t77 = abs(t75);
t79 = t60+t68+1.603e-2;
vM_total_sym = fi12_dot.*((1.0./sqrt(t76.^2+t77.^2).*(t77.*1.0./sqrt(t75.*t79).*(t79.*(t57+t64+(t2.*t52.*(t71-t80))./5.0e+1+(t3.*t51.*(t71-t80))./5.0e+1)+t75.*(t59+t66+(t2.*t54.*(t71-t80))./5.0e+1+(t3.*t53.*(t71-t80))./5.0e+1))-t76.*1.0./sqrt(t74.*t78).*(t78.*(t58+t67-(t2.*t51.*(t71-t80))./5.0e+1+(t3.*t52.*(t71-t80))./5.0e+1)+t74.*(t60+t68-(t2.*t53.*(t71-t80))./5.0e+1+(t3.*t54.*(t71-t80))./5.0e+1))))./2.0-(t8.*t18.*t19)./5.0e+1)+(fi13_dot.*t8.*t18.*t19)./5.0e+1;
end
