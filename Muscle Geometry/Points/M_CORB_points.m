function [p1A_subs,p1B_subs,dummy] = M_CORB_points(fi12)
%M_CORB_points
%    [p1A_subs,p1B_subs,DUMMY] = M_CORB_points(FI12)

%    This function was generated by the Symbolic Math Toolbox version 24.2.
%    14-May-2025 15:34:07

t2 = NaN;
t3 = cos(fi12);
t4 = sin(fi12);
p1A_subs = [t3.*1.6485e-1-t4.*1.76e-3;t3.*1.76e-3+t4.*1.6485e-1];
if nargout > 1
    p1B_subs = [3.467e-2;8.06e-3];
end
if nargout > 2
    dummy = [t2;t2];
end
end
