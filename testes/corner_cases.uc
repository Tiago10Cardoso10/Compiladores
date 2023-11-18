int f(void) {}

int f(void) {                 // in variable declarations with assignments...
    int a, b, c = (5, 6, 7);  // ...comma expressions require parentheses
    double d = (b = 7, c = 5, b + c);
}

void e(void){ {{;{}};{;{;}}} }
