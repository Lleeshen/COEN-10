<!-- Lyman Shen, 9/29/2016 -->
<html>
	<head>
		<title>Multiplication Game - Start</title>
	</head>
	<body style="background-color:green;font-size:200%">
		<h1 style="text-align:center">Multiplication Game</h1>
		<?php
			$i = rand(0,12);
			$j = rand(0,12); //Make 2 Random variables
			echo "$i"." x "."$j"." ="; //Show equation on screen
		?>
		<br />
		<form action=mult2.php method="POST">
			<input type="hidden" name="i" value="<?php echo $i; ?>" />
			<input type="hidden" name="j" value="<?php echo $j; ?>" /> <!--Send the variables to other page -->
			<input type="number" name="k" /> <!--User input, send to other page -->
			<input type="submit" value="Calculate!" />
		</form>
	</body>	
</html>
