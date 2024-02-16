clear;
x1=-5:0.1:5; % 探索範囲の設定
x2=-5:0.1:5; % 探索範囲の設定
[X1,X2]=meshgrid(x1,x2);
Z=X1.*exp(-(X1.^2+X2.^2)); % 関数値の計算
[C,I]=min(Z(:)); % Z(:)で２次元配列を１次元化している
[x1idx,x2idx]=ind2sub(size(Z),I); % Iは１次元化した配列上のインデックス
x1(x1idx)
x2(x2idx)