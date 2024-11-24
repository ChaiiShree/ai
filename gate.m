%AND Gate: 
% Define input and target for AND gate 
inputs = [0 0; 0 1; 1 0; 1 1]'; 
targets = [0 0 0 1]; 
% Create and configure the network 
net = feedforwardnet(2);  % 2 neurons in hidden layer 
net = configure(net, inputs, targets); 
% Train the network 
net = train(net, inputs, targets); 
% Test the network 
output = net(inputs); 
disp('AND Gate Output:'); 
disp(round(output));  % Rounds to 0 or 1 for binary output 

%OR Gate: 
% Define input and target for OR gate 
inputs = [0 0; 0 1; 1 0; 1 1]'; 
targets = [0 1 1 1]; 
% Create and configure the network 
net = feedforwardnet(2);  % 2 neurons in hidden layer 
net = configure(net, inputs, targets); 
% Train the network 
net = train(net, inputs, targets); 
% Test the network 
output = net(inputs); 
disp('OR Gate Output:'); 
disp(round(output)); 

%XOR Gate: 
% Define input and target for XOR gate 
inputs = [0 0; 0 1; 1 0; 1 1]'; 
targets = [0 1 1 0]; 
% Create and configure the network 
net = feedforwardnet(3);  % 3 neurons in hidden layer for XOR 
net = configure(net, inputs, targets); 
% Train the network 
net = train(net, inputs, targets); 
% Test the network 
output = net(inputs); 
disp('XOR Gate Output:'); 
disp(round(output));