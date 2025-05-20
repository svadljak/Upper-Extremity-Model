Parameters_OpenSim;

%% SKELETAL PARAMETERS
    g = 9.81;

    % Lengths
        L2 = 0.2908; % z OpenSimu
        LS2 = L2/2;
        L3 = 0.236; % z OpenSimu
        LS3 = L3/2;

        HUrad = 0.02;   % radius of humeroulnar joints
    
    % Mass parameters
        m2 = 2.0519;
        m3 = 0.5464 + 0.5464;  % ulna+radius [kg]
        I2S2 = 0.0208;
        I3S3 = 0.006;
           
        G2 = m2*g;
        G3 = m3*g;

    
    % Joint damping - torsional
        dampingOn = 1; % ON/OFF
        b12 = dampingOn*0.2 ; %0.09;
        b23 = dampingOn*0.2; %0.09;

%% MUSCLE PARAMETERS
    tauD = 50/1000; % 50 ms
    tauA = 15/1000; % 10 ms
    
    str_names = {'M_CORB', 'M_TMAJ', 'M_DELT', 'M_TRIPB.CMED', 'M_TRIPB.CLAT', 'M_TRIPB.CLONG'};

    % M. CORACOBRACHIALIS
        M_CORB.ratio = muscles.(selected_muscles{1}).ratio;
        % Origin - Insertion
            M_CORB.x1B = muscles.(selected_muscles{1}).attachments.P1.x;
            M_CORB.y1B = muscles.(selected_muscles{1}).attachments.P1.y;
            M_CORB.x2A = muscles.(selected_muscles{1}).attachments.P2.x;
            M_CORB.y2A = muscles.(selected_muscles{1}).attachments.P2.y;
        % Muscle length, force
            M_CORB.LM0 = muscles.(selected_muscles{1}).LM0;
            M_CORB.LTs = muscles.(selected_muscles{1}).LTs;
            M_CORB.alpha0 = muscles.(selected_muscles{1}).alpha0;      
            M_CORB.FM0 = muscles.(selected_muscles{1}).FM0;

    % M. TERES MAJOR
        M_TMAJ.ratio = muscles.(selected_muscles{2}).ratio;
        % Origin - Insertion
            M_TMAJ.x1B = muscles.(selected_muscles{2}).attachments.P1.x;
            M_TMAJ.y1B = muscles.(selected_muscles{2}).attachments.P1.y;
            M_TMAJ.x2A = muscles.(selected_muscles{2}).attachments.P2.x;
            M_TMAJ.y2A = muscles.(selected_muscles{2}).attachments.P2.y;
        % Muscle length, force
            M_TMAJ.LM0 = muscles.(selected_muscles{2}).LM0;
            M_TMAJ.LTs = muscles.(selected_muscles{2}).LTs;
            M_TMAJ.alpha0 = muscles.(selected_muscles{2}).alpha0; 
            M_TMAJ.FM0 = muscles.(selected_muscles{2}).FM0;


    % M. DELTOIDEUS - pars clavicuralis
        M_DELT.ratio = muscles.(selected_muscles{3}).ratio;
        % Origin - Insertion
            M_DELT.x1B = muscles.(selected_muscles{3}).attachments.P1.x;
            M_DELT.y1B = muscles.(selected_muscles{3}).attachments.P1.y;
            M_DELT.x2A = muscles.(selected_muscles{3}).attachments.P2.x;
            M_DELT.y2A = muscles.(selected_muscles{3}).attachments.P2.y;
        % Muscle length, force
            M_DELT.LM0 = muscles.(selected_muscles{3}).LM0;
            M_DELT.LTs = muscles.(selected_muscles{3}).LTs;
            M_DELT.alpha0 = muscles.(selected_muscles{3}).alpha0;
            M_DELT.FM0 = muscles.(selected_muscles{3}).FM0;


    % M. TRICEPS BRACHII
        r = HUrad;
        % Caput mediale
            M_TRIPB.CMED.ratio = muscles.(selected_muscles{4}).ratio;
            % Origin - Insertion
                M_TRIPB.CMED.x2B = muscles.(selected_muscles{4}).attachments.P1.x;
                M_TRIPB.CMED.y2B = muscles.(selected_muscles{4}).attachments.P1.y;
                M_TRIPB.CMED.x3A = muscles.(selected_muscles{4}).attachments.P2.x;
                M_TRIPB.CMED.y3A = muscles.(selected_muscles{4}).attachments.P2.y;
                M_TRIPB.CMED.x3A = 0.01;
                M_TRIPB.CMED.y3A = - sqrt(r^2 - M_TRIPB.CMED.x3A^2);
            % Wrapping - circular
                % r = sqrt(M_TRIPB.CMED.x3A^2 + M_TRIPB.CMED.y3A^2);
                % W2 - humerus
                    M_TRIPB.CMED.alpha2 = acos(r/(L2-M_TRIPB.CMED.x2B));
                    M_TRIPB.CMED.x2W2 = L2 - r*r/(L2-M_TRIPB.CMED.x2B);
                    M_TRIPB.CMED.y2W2 = -r*sin(M_TRIPB.CMED.alpha2);
            % Muscle length, force
                M_TRIPB.CMED.LM0 = muscles.(selected_muscles{4}).LM0;
                M_TRIPB.CMED.LTs = muscles.(selected_muscles{4}).LTs;
                M_TRIPB.CMED.alpha0 = muscles.(selected_muscles{4}).alpha0;
                M_TRIPB.CMED.FM0 = muscles.(selected_muscles{4}).FM0;


        % Caput laterale
            M_TRIPB.CLAT.ratio = muscles.(selected_muscles{5}).ratio;
            % Origin - insertion
                M_TRIPB.CLAT.x2B = muscles.(selected_muscles{5}).attachments.P1.x;
                M_TRIPB.CLAT.y2B = muscles.(selected_muscles{5}).attachments.P1.y;
                M_TRIPB.CLAT.x3A = muscles.(selected_muscles{5}).attachments.P2.x;
                M_TRIPB.CLAT.y3A = muscles.(selected_muscles{5}).attachments.P2.y;
                M_TRIPB.CLAT.x3A = M_TRIPB.CMED.x3A;
                M_TRIPB.CLAT.y3A = M_TRIPB.CMED.y3A;
            % Wrapping - circular
                % r = sqrt(M_TRIPB.CLAT.x3A^2 + M_TRIPB.CLAT.y3A^2);
                % W2 - humerus
                    M_TRIPB.CLAT.alpha2 = acos(r/(L2-M_TRIPB.CLAT.x2B));
                    M_TRIPB.CLAT.x2W2 = L2 - r*r/(L2-M_TRIPB.CLAT.x2B);
                    M_TRIPB.CLAT.y2W2 = -r*sin(M_TRIPB.CLAT.alpha2);
            % Muscle length, force
                M_TRIPB.CLAT.LM0 = muscles.(selected_muscles{5}).LM0;
                M_TRIPB.CLAT.LTs = muscles.(selected_muscles{5}).LTs;
                M_TRIPB.CLAT.alpha0 = muscles.(selected_muscles{5}).alpha0;
                M_TRIPB.CLAT.FM0 = muscles.(selected_muscles{5}).FM0;

            
        % Caput longum
            M_TRIPB.CLONG.ratio = muscles.(selected_muscles{6}).ratio;
            % Origin - insertion
                M_TRIPB.CLONG.x1B = muscles.(selected_muscles{6}).attachments.P1.x;
                M_TRIPB.CLONG.y1B = muscles.(selected_muscles{6}).attachments.P1.y;
                M_TRIPB.CLONG.x3A = muscles.(selected_muscles{6}).attachments.P2.x;
                M_TRIPB.CLONG.y3A = muscles.(selected_muscles{6}).attachments.P2.y;
                M_TRIPB.CLONG.x3A = M_TRIPB.CMED.x3A;
                M_TRIPB.CLONG.y3A = M_TRIPB.CMED.y3A;
            % Wrapping - circular
                % r = sqrt(M_TRIPB.CLONG.x3A^2 + M_TRIPB.CLONG.y3A^2);
                % W2 - humerus
                    M_TRIPB.CLONG.r1B = sqrt(M_TRIPB.CLONG.x1B^2 + M_TRIPB.CLONG.y1B^2);
                    M_TRIPB.CLONG.beta1 = atan(M_TRIPB.CLONG.x1B/M_TRIPB.CLONG.y1B);
            % Muscle length, force
                M_TRIPB.CLONG.LM0 = muscles.(selected_muscles{6}).LM0;
                M_TRIPB.CLONG.LTs = muscles.(selected_muscles{6}).LTs;
                M_TRIPB.CLONG.alpha0 = muscles.(selected_muscles{6}).alpha0;
                M_TRIPB.CLONG.FM0 = muscles.(selected_muscles{6}).FM0;


    % M. BICEPS BRACHII
        M_BICB.ratio = muscles.(selected_muscles{7}).ratio;
        % Origin - insertion
            M_BICB.x1B = muscles.(selected_muscles{7}).attachments.P1.x;
            M_BICB.y1B = muscles.(selected_muscles{7}).attachments.P1.y;
            M_BICB.x3A = muscles.(selected_muscles{7}).attachments.P2.x;
            M_BICB.y3A = muscles.(selected_muscles{7}).attachments.P2.y;
        % Muscle length, force
            M_BICB.LM0 = muscles.(selected_muscles{7}).LM0;
            M_BICB.LTs = muscles.(selected_muscles{7}).LTs;
            M_BICB.alpha0 = muscles.(selected_muscles{7}).alpha0;
            M_BICB.FM0 = muscles.(selected_muscles{7}).FM0;


    % M. BRACHIALIS
        M_BRACH.ratio = muscles.(selected_muscles{8}).ratio;
        % Origin - insertion
            M_BRACH.x2B = muscles.(selected_muscles{8}).attachments.P1.x;
            M_BRACH.y2B = muscles.(selected_muscles{8}).attachments.P1.y;
            M_BRACH.x3A = muscles.(selected_muscles{8}).attachments.P2.x;
            M_BRACH.y3A = muscles.(selected_muscles{8}).attachments.P2.y;
        % Muscle length, force
            M_BRACH.LM0 = muscles.(selected_muscles{8}).LM0;
            M_BRACH.LTs = muscles.(selected_muscles{8}).LTs;
            M_BRACH.alpha0 = muscles.(selected_muscles{8}).alpha0;
            M_BRACH.FM0 = muscles.(selected_muscles{8}).FM0;



    % VECTORS OF PARAMETERS
        RATIO = [M_CORB.ratio; M_TMAJ.ratio; M_DELT.ratio; M_TRIPB.CMED.ratio; M_TRIPB.CLAT.ratio; M_TRIPB.CLONG.ratio; M_BICB.ratio; M_BRACH.ratio];
        LM0 = RATIO.*[M_CORB.LM0; M_TMAJ.LM0; M_DELT.LM0; M_TRIPB.CMED.LM0; M_TRIPB.CLAT.LM0; M_TRIPB.CLONG.LM0; M_BICB.LM0; M_BRACH.LM0];
        LTs = RATIO.*[M_CORB.LTs; M_TMAJ.LTs; M_DELT.LTs; M_TRIPB.CMED.LTs; M_TRIPB.CLAT.LTs;  M_TRIPB.CLONG.LTs; M_BICB.LTs; M_BRACH.LTs];
        alpha0 = 180/pi*[M_CORB.alpha0; M_TMAJ.alpha0; M_DELT.alpha0; M_TRIPB.CMED.alpha0; M_TRIPB.CLAT.alpha0;  M_TRIPB.CLONG.alpha0; M_BICB.alpha0; M_BRACH.alpha0]*pi/180;
        FM0 = [M_CORB.FM0; M_TMAJ.FM0; M_DELT.FM0; M_TRIPB.CMED.FM0; M_TRIPB.CLAT.FM0; M_TRIPB.CLONG.FM0; M_BICB.FM0; M_BRACH.FM0];
    
    % Injury
        % zraneni = [0; 0; 0; 0; 0; 0; 0.9; 0.9];
        zraneni = 0;
        FM0 = (1-zraneni).*FM0;


%% SIMULATIONS
    % Controller
        % Activation dynamics
            activ_dyn = 1; % ON / OFF
        Ku = 0;
        if activ_dyn
            Ku = 10;
        end

        Kp = diag([400, 800]);
        Kd = 2*sqrt(Kp);


        
