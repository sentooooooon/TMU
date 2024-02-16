%%%
%%% ��񐔊wII
%%% �ŋ}�~���@
%%%
%%% coded by Nobutaka Ono (onono@tmu.ac.jp), Dec. 2019
%%%

clear;
     
%%% �����l�A�p�����[�^�̐ݒ�
itr=30;           % ������
x=zeros(1,itr);
y=zeros(1,itr);
mu = 0.3;         % �X�e�b�v�T�C�Y

x(1,1)= 1;        % �����l
y(1,1)= 1;        % �����l

%%% �ŋ}�~���@
for n=1:itr-1
  dx =   (1-2*x(1,n)^2)*exp(-x(1,n)^2-y(1,n)^2); % x�����̌v�Z
  dy = -2*x(1,n)*y(1,n)*exp(-x(1,n)^2-y(1,n)^2); % y�����̌v�Z
  x(1,n+1)=x(1,n)-mu*dx;
  y(1,n+1)=y(1,n)-mu*dy;
end

%%% �\��
[X,Y] = meshgrid(-2:0.02:2,-2:0.02:2);
Z = X.*exp(-X.^2 - Y.^2);
contour(X,Y,Z,20); % �������̕\��
xlabel('x');
ylabel('y');
hold on;
for n=1:itr
  plot(x(1,n), y(1,n), 'p');
end
hold off;
