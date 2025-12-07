#include "SakanX/SmartMatchAI.h"

double SmartMatchAI::calculateHarmony(const Student& s1, const Student& s2) {
    // Validate input students
    if (&s1 == nullptr || &s2 == nullptr) {
        throw std::invalid_argument("Null student reference in calculateHarmony");
    }
    if(s1.getGender() != s2.getGender()) return 0.0; // Different genders cannot be matched
    // Calculate harmony based on common tags and lifestyle compatibility
    double commonTags = 0.0;
    const set<Tag*>& tags1 = s1.getTags();
    const set<Tag*>& tags2 = s2.getTags();
    if(tags1.size()<=tags2.size())
        for(Tag* tag1 : tags1) {
            if(tags2.find(tag1)!=tags2.end()) commonTags++;
        }
    else{
        for(Tag* tag2 : tags2) {
            if(tags1.find(tag2)!=tags1.end()) commonTags++;
        }
    }
    double unionSize = s1.getTags().size() + s2.getTags().size() - commonTags;
    double tagSimilarity = unionSize > 0 ? commonTags / unionSize : 0.0;
    int sum1 = s1.calculateTotalTagValue();
    int sum2 = s2.calculateTotalTagValue();
    double valueDifference = abs(sum1 - sum2);

    // Normalize to 0-1 range, then scale as needed
    double harmonyScore = (tagSimilarity * 100.0) - (valueDifference * 0.25);
    if(s1.getMajor() == s2.getMajor()) {
        harmonyScore += 10.0; // Bonus for same major
    }
    if(abs(s1.getAge()-s2.getAge()) > 5) {
        harmonyScore -= 5.0; // Penalty for different age
    }
    if(s1.getNationality() != s2.getNationality()) {
        harmonyScore -= 5.0; // Penalty for different nationality
    }

    if(harmonyScore < 0) harmonyScore = 0.0;
    else if(harmonyScore > 100.0) harmonyScore = 100.0;
    return harmonyScore;
}
