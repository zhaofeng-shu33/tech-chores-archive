		function check(){
			var rightAnswers=new Array(0,0,1,0,1,0,1);
			var userAnswers=new Array();
			var QuestionGroup=document.forms["JudgementForm"];
			var upperLimit=QuestionGroup.length/2;
			for(var j=0;j<upperLimit;j++){
			if((QuestionGroup[2*j].checked && rightAnswers[j]) ||(QuestionGroup[2*j+1].checked && !rightAnswers[j] )){
			   userAnswers[j]=1;
			 }
			else{
			   	userAnswers[j]=0;
			}
			}
			/*
				var rows=document.getElementsByTagName('tr');
				alert(rows[2].childNodes[3].innerHTML);*/
		  result='';
		  for (var x=0;x<userAnswers.length;x++){
		  	if(!userAnswers[x]){
		  		 var y=x+1;
		   		 result = result + "第"+String(y)+"题答错\n";
		   	}
		  }
		  if(result=='')
		  		result = "恭喜你全部回答正确!";
		  alert(result);
		}
		var xmlDom=new ActiveXObject("MSXML2.DOMDocument.4.0");
		xmlDom.async="false";
		xmlDom.load("Einheit6TU1.xml");
		var xmlObjParent=xmlDom.documentElement.childNodes;
		var practiceNum=xmlDom.documentElement.getAttribute('practiceNum');
		
		xmlObj=xmlObjParent.item(0).childNodes;
		//document.write(xmlObj.length);
		//document.write(xmlObj.item(0).text);
		document.getElementById('practiceNum').innerHTML=practiceNum+'&nbsp;';
		document.getElementById('Instructions').innerHTML=xmlObj.item(0).text;
		var j=1;
		while(j<xmlObj.length){
			var sequence=xmlObj.item(j).text;
			document.write('<tr><td class="AddColorToTableCell">'+sequence+'</td>');
			j++;
			document.write('<td>'+xmlObj.item(j).text+'</td>');
			j++;
			document.write('<td class="AddColorToTableCell"><input type="radio" name='+sequence+' value="T"/></td><td class="AddColorToTableCell"><input type="radio" name='+sequence+' value="F"/></td></tr>');
		}
		document.write('</table></form>');
		