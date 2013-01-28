 int MyDate::GetDay()
{
	MyDate temp(*this);
	int holdYear = this->GetYear();
	int holdMonth = this->GetMonth();

	// temp now holds months and days
	temp.SubtractDays(DaysBefore(holdYear));

	// Return the number of days total minus
	// the number of days before the start of the month
	// plus one (calenders aren't zero-indexed)
	temp._days++;
	if(this->IsLeapYear() && holdMonth > 2)
		return (temp._days - (numDaysToMonth[holdMonth] + 1));
	return temp._days - numDaysToMonth[holdMonth];
}