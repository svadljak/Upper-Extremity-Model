function LM_total_sym = M_BRACH_LM(fi12,fi13)
%M_BRACH_LM
%    LM_total_sym = M_BRACH_LM(FI12,FI13)

%    This function was generated by the Symbolic Math Toolbox version 24.2.
%    05-Mar-2025 17:48:45

LM_total_sym = sqrt(abs(cos(fi12).*1.171e-1+cos(fi13)./4.0e+1).^2+abs(sin(fi12).*1.171e-1+sin(fi13)./4.0e+1).^2);
end
