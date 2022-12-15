BEGIN {
    calories = 0;
    max_calories = 0;
}

/[0-9]+/ {
    calories += $1
}

/^$/ {
    printf "End of group: calories = %d\n", calories;
	if ( calories > max_calories ) {
		max_calories = calories;
	}

    calories = 0;
}

END {
    printf "End of file: calories = %d\n", calories;
	if ( calories > max_calories ) {
		max_calories = calories;
	}

	printf "Max is %ld\n", max_calories;
}
