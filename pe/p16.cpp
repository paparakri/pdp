int main(){
	int result = 0;
	 
	BigInteger number = BigInteger.Pow(2, 1000);
	 
	while (number > 0) {
	    result += (int) (number % 10);
	    number /= 10;
	}
}


