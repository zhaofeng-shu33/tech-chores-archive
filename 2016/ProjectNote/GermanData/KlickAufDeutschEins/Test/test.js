function myFunction(audioPath){
		document.getElementById("BGSOUND").src="../../PyAudio/"+audioPath;
	}
	
	
		document.write("<table border='1' align='center'>")
		
		var xmlDom=new ActiveXObject("MSXML2.DOMDocument.4.0");
		xmlDom.async="false";
		xmlDom.load("../Vokabeln6-1_1.xml");
		var xmlObj=xmlDom.documentElement.childNodes;
		for(j=0;j<xmlObj.length;j++){
    		var wordNodeList=xmlObj.item(j).childNodes;
    		for(var i=0;i<wordNodeList.length-1;i++){	
    		var wordDetailNode=wordNodeList.item(i).firstChild;
    		var audioPath=wordNodeList.item(i).getAttribute("audio");
    		var wordLevel=parseInt(wordNodeList.item(i).getAttribute("Level"));
    		document.write('<tr><td>'+wordLevel+'&nbsp;'+wordNodeList.length+'</td></tr>');   		
    		}
    		
	  
		
	
	}
		document.write("</table>");