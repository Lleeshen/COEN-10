<!--Lyman Shen, lab3.php, 10/6/16--!>
<html>
	<head>
		<title> Guee the Number - Result </title>
		<style>
			body{
				background-color:green;
			}
			h1{
				color:blue;
				text-align:center;
			}
			p{
				color:red;
				font-size:24px;
			}
		</style>
	</head>
	<body>
		<h1> Guess the Number Game - Results </h1> <!--Title of Page --!>
		<p>Here is your results! </p>
		<?php
			$i = $_POST["i"];  //Receive form input
			$correct = array(0,0,0,0,0);
			for($j=0;$j<5;$j++)  //Generate array of 5 random numbers
			{	$correct[$j]=rand(1,20);
			}
			for($k=0;$k<5;$k++)
			{	if($i == $correct[$k])  //Search for input
				{	break;  //k is not 5 when found
				}
			}
			echo "You chose the number "."$i";

			if($k!=5) //match found
			{	echo "<p>Congratulations, You're correct!</p>";
			}
			else //match not found
			{	echo "<p>Sorry, You're incorrect</p>";
			}
			echo "The values are ";
			for($l=0;$l<5;$l++)
			{	echo "$correct[$l]"." ";
			}
			echo "<br />";
		?>
		<form action=lab3.html method="POST"> <!--Link back to first page --!>
			<input type="submit" value="Play Again!" />
		</form>
	</body>
</html>
