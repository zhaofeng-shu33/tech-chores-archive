%this matlab script is not tested by me in recent days and is only right in conceptual level.
%change this file path to the audio file in your hard disk
[y,Fs]=audioread('D:\Deutsch Unterricht\Deutsch Band 1 Intention und Vokabeln\091 Einheit6 Vokabel Einfuehrung.mp3');

y=y(:,1);
frameLength=100;
frameNumber=fix(length(y)/frameLength);
E=[];Z=[];
%E is the short time energy array and Z is the over-zero-rate array
for i=1:frameNumber
    frameSignal=y((i-1)*frameLength+1:i*frameLength);
    E(i)=0;Z(i)=0;T=0.01;
    for j=1:frameLength
        E(i)=E(i)+frameSignal(j)^2;
        if(j>1)
            Z(i)=Z(i)+abs(sign(frameSignal(j)-T)-sign(frameSignal(j-1)-T))+abs(sign(frameSignal(j)+T)-sign(frameSignal(j-1)+T));
        end
    end
end

E1=(E>0.2);
Z1=(Z>1);

index=1;
first=false;
cnt=0;
pre=0;
myMap=[];
for i=1:length(E1)
    if(~E1(i))
        cnt=i;
        first=true;
        continue;
    else
        
        if(first)
            myMap(index,:)=[fix((cnt+pre)/2),cnt-pre];
            first=~first;
            index=index+1;
        end
        pre=i;
    end
end
index=1;
x=[];

%change the number 13 to the one you needed.
tmp=sort(myMap(:,2),'descend');
for i=1:length(myMap)
    if(myMap(i,2)>tmp(13))
        x(index,:)=myMap(i,:);
        index=index+1;
    end
end

%if needed, plot the result of cutting.
%E1=double(E1);
%plot(E1);
%hold on;
for i=1:length(x)
    plot([x(i,1),x(i,1)],[0,1],'xy')
end
%hold off;

%if needed, use "sound" to play the audio.
%i=1;
%first=[x(i,1)*frameLength,x(i+1,1)*frameLength];
%sound(y(first(1):first(2)),Fs)

%finally, output the cutting result with "audiowrite")
audiowrite(sprintf('D:/ProjectNote/PyAudio/Text6-2_%d.wav',i),y(first(1):first(2)),Fs);

