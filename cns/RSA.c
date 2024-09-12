RSA

#include <stdio.h>
#include <stdlib.h>


int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Function to perform modular exponentiation
int mod_exp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to find modular multiplicative inverse
int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

int main() {
    int p, q, n, phi, e, d, msg, c;

    printf("Enter P (prime number): ");
    scanf("%d", &p);
    printf("Enter Q (prime number): ");
    scanf("%d", &q);

    // Ensure p and q are prime and different
    if (p == q || p <= 1 || q <= 1) {
        printf("P and Q should be different primes greater than 1.\n");
        return 1;
    }

    n = p * q;
    phi = (p - 1) * (q - 1);

    // Find e such that 1 < e < phi and gcd(e, phi) == 1
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1) {
            break;
        }
    }

    // Find d such that (d * e) % phi = 1
    d = mod_inverse(e, phi);

    printf("Public Key (e, n): (%d, %d)\n", e, n);
    printf("Private Key (d, n): (%d, %d)\n", d, n);

    printf("Enter the message (integer): ");
    scanf("%d", &msg);

    // Encryption
    c = mod_exp(msg, e, n);
    printf("Encrypted data = %d\n", c);

    // Decryption
    int m = mod_exp(c, d, n);
    printf("Original Message Sent = %d\n", m);

    return 0;
}

//output
// Enter P (prime number): 11
// Enter Q (prime number): 19
// Public Key (e, n): (7, 209)
// Private Key (d, n): (103, 209)
// Enter the message (integer): 23
// Encrypted data = 177
// Original Message Sent = 23

