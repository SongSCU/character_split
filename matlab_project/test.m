pred = stackedAERecognition('data/11.png', 1);
fprintf('�����: %d\n', pred);

A = zeros(46,46);
pred = stackedAERecognition(A, 2);
fprintf('�����: %d\n', pred);