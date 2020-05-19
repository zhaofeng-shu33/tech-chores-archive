function myFunction(audioPath){
		document.getElementById("BGSOUND").src="../../PyAudio/"+audioPath;
	}
	
	
		document.write("<table border='1' align='center'>")
		
		var xmlDom=new ActiveXObject("MSXML2.DOMDocument.4.0");
		xmlDom.async="false";
		xmlDom.load("Vokabeln6-1_1.xml");
		var xmlObj=xmlDom.documentElement.childNodes;
		for(j=0;j<xmlObj.length;j++){
    		var wordNodeList=xmlObj.item(j).childNodes;
    		for(var i=0;i<wordNodeList.length-1;i++){	
    		var wordDetailNode=wordNodeList.item(i).firstChild;
    		var audioPath=wordNodeList.item(i).getAttribute("audio");
    		var wordLevel=parseInt(wordNodeList.item(i).getAttribute("Level"));
    		while(wordDetailNode){
    		if(wordDetailNode.nodeName=="description"){
    			if(wordLevel==4){
    				 document.write("<tr><td bgcolor='#c88b48'><sup>*</sup>"+wordDetailNode.text+"</td>");
    			}
    		  else if(wordLevel==6){
    				 document.write("<tr><td bgcolor='#c88b48'><sup>#</sup>"+wordDetailNode.text+"</td>");
    			}		  
    			else{document.write("<tr><td bgcolor='#c88b48'>"+wordDetailNode.text+"</td>"); 
 		  	}
    		}else if(wordDetailNode.nodeName=="TE"){
    			document.write("<td bgcolor='#c88b48'style='font-family:FangSong;font-size:20px;font-weight:bold'>"+wordDetailNode.text+"</td>");
    		}
    		else{
    		var originalWordNode=wordDetailNode.selectSingleNode("or");
    		var reflectiveChangeNode=wordDetailNode.selectSingleNode("reflectiveChange");   		
    		document.write("<td onclick='myFunction(\""+audioPath+"\")'><a title='"+ reflectiveChangeNode.text+ "'>" + originalWordNode.text + "</a></td>");
    		
    		}	
    		wordDetailNode=wordDetailNode.nextSibling;
    		}
    		if(i==0){
    			var audioExamplePath=wordNodeList.item(wordNodeList.length-1).getAttribute("audio");
    			document.write("<td onclick='myFunction(\""+audioExamplePath+"\")' rowspan='"+(wordNodeList.length-1)+"' width='150'>"+wordNodeList.item(wordNodeList.length-1).text+'</td>');
    		}
    		document.write("</tr>");
    		<!--wordNode=wordNode.nextSibling;-->
    		}
    		
	  
		
	
	}	document.write("</table>");