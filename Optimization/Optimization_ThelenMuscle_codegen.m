function activation = Optimization_ThelenMuscle_codegen(Q, b, Fl, Fpe, VM, LM0, a0, alpha0, FM0) %#codegen

    % Ověření pevné velikosti vstupů
    assert(size(Q,1) == 2 && size(Q,2) == 8);
    assert(numel(b) == 2);  
    assert(numel(Fl) == 8);  
    assert(numel(Fpe) == 8);  
    assert(numel(VM) == 8);  
    assert(numel(LM0) == 8);  
    assert(numel(a0) == 8);  
    assert(numel(alpha0) == 8);  
    assert(numel(FM0) == 8);  

    % Dolní a horní meze
    lb = zeros(8,1);
    ub = ones(8,1);

    fun = @(a) cilova(a);
    nonlcon = @(a) constr(a, Q, b, Fl, Fpe, VM, LM0, alpha0, FM0);
    options = optimoptions('fmincon','Algorithm','sqp');

    activation = fmincon(fun, a0, [],[],[],[],lb,ub,nonlcon,options);

    function [c,ceq] = constr(A, Q, b, Fl, Fpe, VM, LM0, alpha0, FM0)
        Af = 0.3;               % a shape factor for the force-velocity relationship
        fMlen = 1.4;            % maximum normalized muscle force achievable when the fiber is lengthening

        VMmax = 10*LM0;

        Fm = zeros(numel(A),1);
        for k = 1 : numel(A)
            a = A(k);
            Vm = VM(k);
            vmmax = VMmax(k);
            if Vm <= 0
                fvm = Af*(4*Vm + vmmax*(3*a + 1)) / (-4*Vm + vmmax*Af*(3*a + 1));
            else
                fvm = (Af*vmmax*(3*a*fMlen - 3*a + fMlen - 1) + 8*Vm*fMlen*(Af + 1)) / (Af*vmmax*(3*a*fMlen - 3*a + fMlen - 1) + 8*Vm*(Af + 1));
            end
            
            % Fm(k) = a*Fl(k)*fvm + Fpe(k);
            Fm(k) = FM0(k)*(a*Fl(k)*fvm + Fpe(k))*cos(alpha0(k));
            if Fm(k) <= 0
                Fm(k) = 0;
            end

        end

        ceq = Q*Fm - b;
        c = [];

    end


    function CF = cilova(a)
        CF = sum(a.^2);
    end
end