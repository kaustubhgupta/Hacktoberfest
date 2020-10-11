<html>
  <head>
    <title>javasvript</title>
    <script>


      function likeunlike(id){
        var likeObj=document.getElementById(id);

         if(likeObj.textContent=="unlike" )
          {
             likeObj.textContent="like";
             likeObj.setAttribute("class","like-btn");
          }
          else
          {
            likeObj.textContent="unlike";
            likeObj.setAttribute("class","like-btn");

          }

      }

      function onButtonClick(){
        var buttonObj =document.getElementById("button-showFriends-hideFriends");
        console.log("buttonObj");
        var mutualFriends=['divyanshu','gaurav','abhijit'];
        var mutualFriendsElement="";
        for(var i=0;i<mutualFriends.length;i++){
        console.log(mutualFriends[i]);
        mutualFriendsElement=mutualFriendsElement+'<li >'+mutualFriends[i]+
        '<button id="'+mutualFriends[i]+'" onclick="likeunlike(\''+mutualFriends[i]+'\')" class="like-btn">like</button></li>';}



      var testEleObj=document.getElementById("test-element")
        testEleObj.innerHTML=mutualFriendsElement;
        console.log("button called");

      if(buttonObj.textContent=="showFriends" )
       {
          buttonObj.textContent="hideFriends";

          buttonObj.setAttribute("class","hideFriends");
          testEleObj.style.display="block";
        }
       else
       {
         buttonObj.textContent="showFriends";

         buttonObj.setAttribute("class","showFriends");
         testEleObj.style.display="none";
       }
     }
    </script>
    <style>
      .showFriends{
        background-color:blue;
        color:white;
        cursor:pointer;
      }
      .hideFriends{
        background-color:green;
        color:white;
        cursor:pointer;


      }
      .showFriends:hover{
        background-color: lightblue;
      }
      .hideFriends:hover{
        background-color: lightgreen;
      }
      .like-btn{
        background-color: blue;
        color: white ;

         }
    </style>
  </head>
  <body>


    <button  id="button-showFriends-hideFriends" class="showFriends" onclick="onButtonClick()">showFriends</button>
    <ol id="test-element" >

    </ol>

  </body>
</html>
