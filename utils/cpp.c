
int ScalarConverter::strToD(std::string str, double* out) {
	int k;
	int j;
	int sign;
	double divisor;

	divisor = 10;
	*out = 0;
	k = 0;
	j = 0;
    
	while (str[k] && std::isspace(str[k])) k++;
	sign = (str[k] == '+') - (str[k] == '-');
	k += (sign != 0);
	if (str.substr(k, 3) == "inf") {
		*out = (sign == -1) ? -INFINITY : INFINITY;
		j += 3;
	} else {
		while (str[k + j] && std::isdigit(str[k + j])) *out = (*out * 10) + (str[k + j++] - '0');
		if (str[k + j] && str[k + j] == '.') k++;
		while (str[k + j] && std::isdigit(str[k + j])) {
			*out += (str[k + j++] - '0') / divisor;
			divisor *= 10;
		}
		*out *= (sign + (sign == 0));
	}
	if (str[k + j] && str[k + j] == 'f' && (j)) k++;
	while (str[k + j] && std::isspace(str[k + j])) k++;
	if (!j && k == str.length()) return (-1);
	return (k + j);
}