function [cost, grad] = softmaxCost(theta, numClasses, inputSize, lambda, data, labels)

% numClasses - the number of classes 
% inputSize - the size N of the input vector
% lambda - weight decay parameter
% data - the N x M input matrix, where each column data(:, i) corresponds to
%        a single test set
% labels - an M x 1 matrix containing the labels corresponding for the input data
%

% Unroll the parameters from theta
theta = reshape(theta, numClasses, inputSize);

numCases = size(data, 2);

groundTruth = full(sparse(labels, 1:numCases, 1));
cost = 0;

thetagrad = zeros(numClasses, inputSize);

%% ---------- YOUR CODE HERE --------------------------------------
%  Instructions: Compute the cost and gradient for softmax regression.
%                You need to compute thetagrad and cost.
%                The groundTruth matrix might come in handy.
M=theta*data;  
M = bsxfun(@minus, M, max(M, [], 1));  
%max(M,[],1)取M中各列最大元素，结果为一个行向量；max(M,[],2)为各行最大元素  
M=exp(M);  
H = bsxfun(@rdivide, M, sum(M));  %归一化公式3  
M=log(H);  
M=M.*groundTruth;  
cost=-1/numCases*sum(sum(M,1),2)+ lambda/2 * sum(sum(theta.^2));  %公式1  
thetagrad=-1/numCases*(groundTruth-H)*data'+lambda * theta;  %公式2  











% ------------------------------------------------------------------
% Unroll the gradient matrices into a vector for minFunc
grad = [thetagrad(:)];
end

