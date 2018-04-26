<!--Lyman Shen, 10/13/16-->
<html>
	<head>
		<title>Lottery Event Results</title>
		<style>
			body
			{
				background-color:yellow;
				color:navy;
				font-size:150%;
			}
			h1
			{
				color:magenta;
				text-align:center;
			}
		</style>
	</head>
	<body>
		<h1>Lottery Event Results</h1>
		<p>Here are your results</p>
		<?php
			//Receive form inputs to an array
			$input = array();
			for($i=0;$i<5;$i++)
			{
				$input[$i] = $_POST["num".$i];
			}
			//Generate array of 5 random numbers
			$correct = array(0,0,0,0,0);
			for($i=0;$i<5;$i++)
			{
				$correct[$i]=rand(1,20);
				//Make sure same number is not generated twice
				for($j=0;$j<$i;$j++)
				{	
					//Check for same values,generate and recheck if same
					if($correct[$j]==$correct[$i])
					{
						$i--;
						break;
					}
				}
			}
			//Check input values for matches
			$counter = 0;
			for($i=0;$i<5;$i++)
			{
				//Check matches against the 
				for($j=0;$j<5;$j++)
				{
					if($input[$i] == $correct [$j])
					{
						$counter++;
					}
				}
			}
			echo "You have "."$counter"." matches."."<br />";
			//Output input numbers
			echo "You inputted the numbers ";
			for($i=0;$i<5;$i++)
			{	
				echo "$input[$i]"." ";
			}
			echo "."."<br />";
			//Output correct numbers
			echo "The right numbers were ";
			for($i=0;$i<5;$i++)
			{	
				echo "$correct[$i]"." ";
			}
			echo "."."<br />";
		?>
		<form action="lab4.html" method="POST">
			<input type="submit" value="Play Again!" />
		</form>
		<a href="/~lshen">Back to main page</a>
	</body>
</html>
