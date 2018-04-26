<!--Lyman Shen, 9/29/16-->
<html>
	<head>
		<title>Multiplication Game - Results</title>
	</head>
	<body style="background-color:red;font-size:200%">
		<h1 style="text-align:center">Multiplication Game</h1>
		<?php
			$i = $_POST["i"];
			$j = $_POST["j"];
			$k = $_POST["k"]; //Receive the data
			echo "You said "."$i"." x "."$j"." is "."$k".".";
			echo "<br />"; //Show user what they typed
			if($k==$i*$j)
				echo "Good Job!"; //User is correct
			else
				echo "The right answer is ".($i*$j)."."; //Tell user the correct answer
		?>
		<form method="POST" action="mult1.php">
			<input type="submit" value="Try again" /> <!--Button to get back to first page -->
		</form>
	</body>
</html>
