%% SKELETAL PARAMETERS
    g = 9.81;

    % Lengths
        L2 = 0.3196;
        L3 = 0.246;
        LS2 = 0.1393;   % vzdalenost teziste 1 od rotacni vazby 01
        LS3 = 0.106;   % vzdalenost teziste 2 od rotacni vazby 12
        GHrad = 0.02;   % radius of glenohumeral joint
        HUrad = 0.02;   % radius of humeroulnar joints
    

    % Mass parameters
        m2 = 1.96;  % humerus [kg]
        m3 = 1.12;  % ulna+radius [kg]
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


    % M. CORACOBRACHIALIS
        % Origin - Insertion
            M_CORB.x1B = 0.0296;
            M_CORB.y1B = 0;
            M_CORB.x2A = 0.1533;
            M_CORB.y2A = 0;
        % Muscle length, force
            M_CORB.LM0 = 1.4*0.0683; % 1.4*
            M_CORB.LTs = 0.4*0.104; % 0.4*
            M_CORB.alpha0 = 0;        
            M_CORB.FM0 = 648.2;  % [N]

    % M. TERES MAJOR
        % Origin - Insertion
            M_TMAJ.x1B = -0.0583;
            M_TMAJ.y1B = -0.0733;
            M_TMAJ.x2A = 0.0421;
            M_TMAJ.y2A = 0;
        % Muscle length, force
            M_TMAJ.LM0 = 0.65*0.141; % 0.65*
            M_TMAJ.LTs = 1*0.006; % 1*
            M_TMAJ.alpha0 = 0;
            M_TMAJ.FM0 = 851.2;  % [N]


    % M. DELTOIDEUS - pars clavicuralis
        % Origin - Insertion
            M_DELT.x1B = 0.0396;
            M_DELT.y1B = 0.0283;
            M_DELT.x2A = 0.1091;
            M_DELT.y2A = 0;
        % Muscle length, force
            M_DELT.LM0 = 0.8*0.0949; % 0.8*
            M_DELT.LTs = 0.4*0.088; % 0.4*
            M_DELT.alpha0 = 5*pi/180; % 0
            M_DELT.FM0 = 707.7;


    % M. TRICEPS BRACHII
        r = HUrad;
        % M_TRIPB.CMED.r = r;

        % Caput mediale
            % Origin - Insertion
                M_TRIPB.CMED.y2B = 0;
                M_TRIPB.CMED.x2B = 0.1417;
                M_TRIPB.CMED.x3A = 0.0362;
                M_TRIPB.CMED.y3A = 0;
            % Wrapping - circular
                % W2 - humerus
                    M_TRIPB.CMED.alpha2 = acos(r/(L2-M_TRIPB.CMED.x2B));
                    M_TRIPB.CMED.x2W2 = L2 - r*r/(L2-M_TRIPB.CMED.x2B);
                    M_TRIPB.CMED.y2W2 = -r*sin(M_TRIPB.CMED.alpha2);
                % W3 - ulna-radius
                    M_TRIPB.CMED.alpha3 = acos(r/M_TRIPB.CMED.x3A);
                    M_TRIPB.CMED.x3W3 = r*r/M_TRIPB.CMED.x3A;
                    M_TRIPB.CMED.y3W3 = -r*sin(M_TRIPB.CMED.alpha3);
            % Muscle length, force
                M_TRIPB.CMED.LM0 = 1*0.0584; % 1.27*0.0584
                M_TRIPB.CMED.LTs = 1.5*0.1168; % 1.5*0.1168
                M_TRIPB.CMED.alpha0 = 0;
                M_TRIPB.CMED.FM0 = 1580.6/3;  % [N]


        % Caput laterale
            % Origin - insertion
                M_TRIPB.CLAT.x2B = M_TRIPB.CMED.x2B/2;
                M_TRIPB.CLAT.y2B = M_TRIPB.CMED.y2B;
                M_TRIPB.CLAT.x3A = M_TRIPB.CMED.x3A;
                M_TRIPB.CLAT.y3A = M_TRIPB.CMED.y3A;
            % Wrapping - circular
                % W2 - humerus
                    M_TRIPB.CLAT.alpha2 = acos(r/(L2-M_TRIPB.CLAT.x2B));
                    M_TRIPB.CLAT.x2W2 = L2 - r*r/(L2-M_TRIPB.CLAT.x2B);
                    M_TRIPB.CLAT.y2W2 = -r*sin(M_TRIPB.CLAT.alpha2);
                % W3 - ulna-radius
                    M_TRIPB.CLAT.alpha3 = acos(r/M_TRIPB.CLAT.x3A);
                    M_TRIPB.CLAT.x3W3 = r*r/M_TRIPB.CLAT.x3A;
                    M_TRIPB.CLAT.y3W3 = -r*sin(M_TRIPB.CLAT.alpha3);
            % Muscle length, force
                M_TRIPB.CLAT.LM0 = 1*0.0881; % 1.45*0.0881
                M_TRIPB.CLAT.LTs = 1.2*0.1762; % 0.65*0.1762
                M_TRIPB.CLAT.alpha0 = 5*pi/180; % [rad]
                M_TRIPB.CLAT.FM0 = 1580.6/3;  % [N]

            
        % Caput longum
            % Origin - insertion
                M_TRIPB.CLONG.x1B = -0.0231;
                M_TRIPB.CLONG.y1B = -0.0153;
                M_TRIPB.CLONG.x3A = M_TRIPB.CMED.x3A;
                M_TRIPB.CLONG.y3A = M_TRIPB.CMED.y3A;
                % M_TRIPB.CLONG.r = HUrad;
            % Wrapping - circular
                % W2 - humerus
                    M_TRIPB.CLONG.r1B = sqrt(M_TRIPB.CLONG.x1B^2 + M_TRIPB.CLONG.y1B^2);
                    M_TRIPB.CLONG.beta1 = atan(M_TRIPB.CLONG.x1B/M_TRIPB.CLONG.y1B);
                % W3 - ulna-radius
                    M_TRIPB.CLONG.alpha3 = acos(r/M_TRIPB.CLONG.x3A);
                    M_TRIPB.CLONG.x3W3 = r*r/M_TRIPB.CLONG.x3A;
                    M_TRIPB.CLONG.y3W3 = -r*sin(M_TRIPB.CLONG.alpha3);
            % Muscle length, force
                M_TRIPB.CLONG.LM0 = 1.5*0.0969; % 1.2*0.0969
                M_TRIPB.CLONG.LTs = 1*0.241; % 1*0.241
                M_TRIPB.CLONG.alpha0 = 10*pi/180;
                M_TRIPB.CLONG.FM0 = 1580.6/3;


    % M. BICEPS BRACHII
        % Origin - insertion
            M_BICB.x1B = 0.01;
            M_BICB.y1B = 0.0355;
            M_BICB.x3A = 0.0631;
            M_BICB.y3A = 0;
        % Muscle length, force
            M_BICB.LM0 = 1.4*0.1412; % 1.4*
            M_BICB.LTs = 0.5*0.257; % 0.5*
            M_BICB.alpha0 = 0;
            M_BICB.FM0 = 485.8; % [N]


    % M. BRACHIALIS
        % Origin - insertion
            M_BRACH.x3A = 0.025;
            M_BRACH.y3A = 0;
            M_BRACH.x2B = 0.2025;
            M_BRACH.y2B = 0;
        % Muscle length, force
            M_BRACH.LM0 = 1*0.0762; % 1*0.0762
            M_BRACH.LTs = 0.275*0.1524; % 0.55*0.0762
            M_BRACH.alpha0 = 0;
            M_BRACH.FM0 = 1177.37;  % [N]



    % VECTORS OF PARAMETERS
        LM0 = [M_CORB.LM0; M_TMAJ.LM0; M_DELT.LM0; M_TRIPB.CMED.LM0; M_TRIPB.CLAT.LM0; M_TRIPB.CLONG.LM0; M_BICB.LM0; M_BRACH.LM0];
        LTs = [M_CORB.LTs; M_TMAJ.LTs; M_DELT.LTs; M_TRIPB.CMED.LTs; M_TRIPB.CLAT.LTs;  M_TRIPB.CLONG.LTs; M_BICB.LTs; M_BRACH.LTs];
        alpha0 = [M_CORB.alpha0; M_TMAJ.alpha0; M_DELT.alpha0; M_TRIPB.CMED.alpha0; M_TRIPB.CLAT.alpha0;  M_TRIPB.CLONG.alpha0; M_BICB.alpha0; M_BRACH.alpha0];
        FM0 = [M_CORB.FM0; M_TMAJ.FM0; M_DELT.FM0; M_TRIPB.CMED.FM0; M_TRIPB.CLAT.FM0; M_TRIPB.CLONG.FM0; M_BICB.FM0; M_BRACH.FM0];
        % W = LM0.*sin(alpha0);
    
    % Injury
        % zraneni = 0.7; % <0;1> = procentualni zraneni ruky
        % zraneni = [0; 0; 0; 0; 0; 0; 0.9; 0.9];
        zraneni = 0;
        FM0 = (1-zraneni).*FM0;


%% SIMULATIONS
    % Upper Limb boundaries
        fi12ub = 0;
        fi12lb = -0.9*pi/2;

        fi23ub = 150/180*pi;
        fi23lb = 8/180*pi;


    % Controller
        % Activation dynamics
            activ_dyn = 1; % ON / OFF
        Ku = 0;
        if activ_dyn
            Ku = 10;
        end

        Kp = diag([400, 800]);
        Kd = 2*sqrt(Kp);


        
