
#include <stdio.h>


long long int mod_exp(long long int base, long long int exp, long long int mod) {
    long long int result = 1;
    base = base % mod; 

    while (exp > 0) {
        if (exp % 2 == 1) { 
            result = (result * base) % mod;
        }
        exp = exp >> 1; 
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long long int P, G, a, b, x, y, ka, kb;

   
    P = 23; 
    G = 9;  

    printf("The value of P: %lld\n", P);
    printf("The value of G: %lld\n\n", G);

    a = 4;
    printf("The private key a for Alice: %lld\n", a);
    x = mod_exp(G, a, P); 

 
    b = 3;
    printf("The private key b for Bob: %lld\n\n", b);
    y = mod_exp(G, b, P); 

    
    ka = mod_exp(y, a, P); 
    kb = mod_exp(x, b, P); 

    printf("Secret key for Alice: %lld\n", ka);
    printf("Secret Key for Bob: %lld\n", kb);


    if (ka == kb) {
        printf("Shared secret is correctly computed.\n");
    } else {
        printf("Error in shared secret computation.\n");
    }

    return 0;
}
//output
The value of P: 23
The value of G: 9

The private key a for Alice: 4
The private key b for Bob: 3

Secret key for Alice: 9
Secret Key for Bob: 9
Shared secret is correctly computed.

//using html and javascript

<!DOCTYPE html>
<html>
<head>
  <title>Diffie-Hellman Key Exchange</title>
</head>
<body>
<script>

// Power function to return value of a ^ b mod P
function power(a, b, p) 
{
	if (b == 1)
		return a;
	else
		return((Math.pow(a, b)) % p);
}

// Driver code
var P, G, x, a, y, b, ka, kb;

// Both the persons will agree upon the
// public keys G and P

P = parseInt(prompt("Enter a prime number P:"));
document.write("The value of P: " + P + "<br>");

G = parseInt(prompt("Enter a primitive root G:"));
document.write("The value of G: " + G + "<br>");

// Alice will choose the private key a
// a is the chosen private key
a = parseInt(prompt("Enter the private key for Alice (a):")); 
document.write("The private key (a) for Alice: " + a + "<br>");

// Gets the generated key
x = power(G, a, P);

// Bob will choose the private key b
// b is the chosen private key 
b = parseInt(prompt("Enter the private key for Bob (b):")); 
document.write("The private key (b) for Bob: " + b + "<br>");

// Gets the generated key
y = power(G, b, P); 

// Generating the secret key after the exchange
// of keys
ka = power(y, a, P); // Secret key for Alice
kb = power(x, b, P); // Secret key for Bob

document.write("Secret key for Alice is: " + ka + "<br>");
document.write("Secret key for Bob is: " + kb + "<br>");

</script>
</body>
</html>


//output

The value of P: 23
The value of G: 9
The private key (a) for Alice: 4
The private key (b) for Bob: 3
Secret key for Alice is: 9
Secret key for Bob is: 9
