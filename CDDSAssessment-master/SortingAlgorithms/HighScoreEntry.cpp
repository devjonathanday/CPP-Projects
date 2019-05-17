#include"HighScoreEntry.h"
#include<string>

HighScoreEntry::HighScoreEntry() {}
HighScoreEntry::~HighScoreEntry() {}

HighScoreEntry::HighScoreEntry(string _name, int _score, int _level)
{
	name = _name;
	score = _score;
	level = _level;
}
bool HighScoreEntry::operator>(HighScoreEntry& entry) {
	return (*this).score > entry.score;
}
bool HighScoreEntry::operator<(HighScoreEntry& entry) {
	return (*this).score < entry.score;
}
bool HighScoreEntry::operator>=(HighScoreEntry& entry) {
	return (*this).score >= entry.score;
}
bool HighScoreEntry::operator<=(HighScoreEntry& entry) {
	return (*this).score <= entry.score;
}
void HighScoreEntry::operator=(HighScoreEntry * entry) {
	(*this) = *entry;
}