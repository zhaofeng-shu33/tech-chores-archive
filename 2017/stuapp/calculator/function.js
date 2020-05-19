'use strict';

var tempnum=0;
var tempoperator=0;
var num_stack=new Array();
var operator_stack=new Array();
var tempresult=0;
var pointflag=0;
var a=1;
var previous_string='';
function addnum(num){
	if (pointflag==1) {
		a=a*10;
		tempnum=tempnum+num/a;
	}
	else
		tempnum=tempnum*10+num;
    if(previous_string)
        output(previous_string,tempnum);
    else
        output('',tempnum);
};
function delnum(){
	if (pointflag==1) {
		if (a==1) {
			pointflag=0;
		}
		else{
			tempnum=tempnum*a-(tempnum*a)%10;
			tempnum=tempnum/a;
			a=a/10;
		};
	}
	else
		tempnum=(tempnum-tempnum%10)/10;
	output('',tempnum);
};
function operator(character){
    previous_string+=tempnum;
	getresult();
	a=1;
	pointflag=0;
    //compare the current operator precedence with the operator on the top of the operator stack
	switch(character){
		case 1:tempoperator=1;previous_string+='+';break;
		case 2:tempoperator=2;previous_string+='-';break;
		case 3:tempoperator=3;previous_string+='*';break;
		case 4:tempoperator=4;previous_string+='/';break;
	};
    if(operator_stack.length!=0 && tempoperator-operator_stack[operator_stack.length-1]>1)
        operator_stack.push(tempoperator);
    else if(operator_stack.length==0)
        operator_stack.push(tempoperator);
    else{ //calculate directly!
        //get the two numbers from num stack
        var n1=num_stack.pop();
        var o1=operator_stack.pop();
        switch(o1){
            case 1:num_stack.push(num_stack.pop()+n1);break;
            case 2:num_stack.push(num_stack.pop()-n1);break;
            case 3:num_stack.push(num_stack.pop()*n1);break;
            case 4:num_stack.push(num_stack.pop()/n1);break;        
        };
        //push the current operator into the stack
        operator_stack.push(tempoperator);
    }
    //output the first number and operator in the first line of output panel
    output(previous_string,tempresult);
};
function addpoint(){
	pointflag=1;
	output('',tempnum+".");
};
function getresult(){
    //add number finished, push the previous number to the stack
    num_stack.push(tempnum);
	switch(tempoperator){
		case 0:tempresult=tempnum;break;
		case 1:tempresult=tempresult+tempnum;break;
		case 2:tempresult=tempresult-tempnum;break;
		case 3:tempresult=tempresult*tempnum;break;
		case 4:tempresult=tempresult/tempnum;break;        
	};
	tempnum=0;        
};
function allclear(){
	tempresult=0;
	tempnum=0;
	tempoperator=0;
	pointflag=0;
    previous_string='';
    num_stack=[];
    operator_stack=[];
	output('',tempresult);
};
function answers(){
    getresult();
    //calculate the remaining items in the operator and num stack
    while(operator_stack.length!=0){
        var n1=num_stack.pop();
        var o1=operator_stack.pop();
        switch(o1){
            case 1:num_stack.push(num_stack.pop()+n1);break;
            case 2:num_stack.push(num_stack.pop()-n1);break;
            case 3:num_stack.push(num_stack.pop()*n1);break;
            case 4:num_stack.push(num_stack.pop()/n1);break;        
        };        
    }
    //get the last num from the num_stack
    output('',num_stack.pop());
    previous_string='';
	tempoperator=0;    

}
function output(content_first_line,content_second_line){
    document.getElementById("output").innerHTML=content_first_line+'<br/>'+content_second_line;
}