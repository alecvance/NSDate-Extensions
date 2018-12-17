/*
 Originally by Erica Sadun, http://ericasadun.com
 iPhone Developer's Cookbook 3.x and beyond
 BSD License, Use at your own risk
 
 this fork by Alec Vance https://www.juggleware.com
 */

#import <Foundation/Foundation.h>

#define D_MINUTE	60
#define D_HOUR		3600
#define D_DAY		86400
#define D_WEEK		604800
#define D_YEAR		31556926

@interface NSDate (Utilities)
+ (NSCalendar *) currentCalendar; // avoid bottlenecks
+ (NSTimeZone *)genericTimeZoneForLongitude:(double)lon;

// Relative dates from the current system date (now)
+ (NSDate *) dateTomorrow;
+ (NSDate *) dateYesterday;
+ (NSDate *) dateWithDaysFromNow: (NSInteger) days;
+ (NSDate *) dateWithDaysBeforeNow: (NSInteger) days;
+ (NSDate *) dateWithHoursFromNow: (NSInteger) dHours;
+ (NSDate *) dateWithHoursBeforeNow: (NSInteger) dHours;
+ (NSDate *) dateWithMinutesFromNow: (NSInteger) dMinutes;
+ (NSDate *) dateWithMinutesBeforeNow: (NSInteger) dMinutes;

// Implies Gregorian calendar
+(NSDate *)dateForGregorianYear:(int)year Month:(int)month Day:(int)day;

// # of weekdays
+(int)numberOfDaysInWeek;

// String names for weekdays
+(NSString *)nameForWeekdayNumbered:(int)n;
+(NSString *)shortNameForWeekdayNumbered:(int)n;

// Short string utilities
- (NSString *) stringWithDateStyle: (NSDateFormatterStyle) dateStyle timeStyle: (NSDateFormatterStyle) timeStyle;
- (NSString *) stringWithFormat: (NSString *) format;
@property (nonatomic, readonly) NSString *shortString;
@property (nonatomic, readonly) NSString *shortDateString;
@property (nonatomic, readonly) NSString *shortTimeString;
@property (nonatomic, readonly) NSString *mediumString;
@property (nonatomic, readonly) NSString *mediumDateString;
@property (nonatomic, readonly) NSString *mediumTimeString;
@property (nonatomic, readonly) NSString *longString;
@property (nonatomic, readonly) NSString *longDateString;
@property (nonatomic, readonly) NSString *longTimeString;

// Comparing dates
- (BOOL) isEqualToDateIgnoringTime: (NSDate *) aDate;

// Returns YES if same day (time can be different)
-(BOOL)isSameLocalDayAsDate:(NSDate *)otherDate;
-(BOOL)isSameDayAsDate:(NSDate *)otherDate usingCalendar:(NSCalendar *)calendar;
    //calendar should already have time zone set!!
-(BOOL)isSameUTDayAsDate:(NSDate *)otherDate;

- (BOOL) isToday;
- (BOOL) isTomorrow;
- (BOOL) isYesterday;

- (BOOL) isSameWeekOfYearAsDate: (NSDate *) aDate;
- (BOOL) isThisWeek;
- (BOOL) isNextWeek;
- (BOOL) isLastWeek;

- (BOOL) isSameMonthAsDate: (NSDate *) aDate;
- (BOOL) isThisMonth;
- (BOOL) isNextMonth;
- (BOOL) isLastMonth;

- (BOOL) isSameYearAsDate: (NSDate *) aDate;
- (BOOL) isThisYear;
- (BOOL) isNextYear;
- (BOOL) isLastYear;

- (BOOL) isEarlierThanDate: (NSDate *) aDate;
- (BOOL) isLaterThanDate: (NSDate *) aDate;

-(BOOL)isEarlierOrEqualToDate:(NSDate *)otherDate;
-(BOOL)isLaterOrEqualToDate:(NSDate *)otherDate;

- (BOOL) isInFuture;
- (BOOL) isInPast;

// Date roles
- (BOOL) isTypicallyWorkday;
- (BOOL) isTypicallyWeekend;

// Adjusting dates
- (NSDate *) dateByAddingYears: (NSInteger) dYears;
- (NSDate *) dateBySubtractingYears: (NSInteger) dYears;
- (NSDate *) dateByAddingMonths: (NSInteger) dMonths;
- (NSDate *) dateBySubtractingMonths: (NSInteger) dMonths;
- (NSDate *) dateByAddingDays: (NSInteger) dDays;
- (NSDate *) dateBySubtractingDays: (NSInteger) dDays;
- (NSDate *) dateByAddingHours: (NSInteger) dHours;
- (NSDate *) dateBySubtractingHours: (NSInteger) dHours;
- (NSDate *) dateByAddingMinutes: (NSInteger) dMinutes;
- (NSDate *) dateBySubtractingMinutes: (NSInteger) dMinutes;

- (NSDate *) nextDay;
- (NSDate *) previousDay;

- (NSDate *) averagedWith: (NSDate *)otherDate;

//components
- (NSDateComponents *) componentsForDate; // gets all standard components plus ordinals
- (NSDateComponents *) componentsForDateWithTimeZone: (NSTimeZone *)timeZone;
- (NSDateComponents *) componentsWithOffsetFromDate: (NSDate *) aDate;


// Date extremes
- (NSDate *) dateAtStartOfDay; //using current calendar (and timezone) -- can cause issues with dates in different time zone state than today
- (NSDate *) dateAtEndOfDay; //using current calendar (and timezone) -- can cause issues with dates in different time zone state than today

//Even if you're still using Gregorian calendar, you might want to change the time zone!
- (NSDate *) dateAtStartOfDayUsingCalendar:(NSCalendar *)calendar;
- (NSDate *) dateAtEndOfDayUsingCalendar:(NSCalendar *)calendar;

- (NSDate *) dateAtStartOfDayGMT;
- (NSDate *) dateAtEndOfDayGMT;

- (NSDate *) dateForMiddayAtLongitude: (double)lon;

// Retrieving intervals
- (NSInteger) minutesAfterDate: (NSDate *) aDate;
- (NSInteger) minutesBeforeDate: (NSDate *) aDate;
- (NSInteger) hoursAfterDate: (NSDate *) aDate;
- (NSInteger) hoursBeforeDate: (NSDate *) aDate;
- (NSInteger) daysAfterDate: (NSDate *) aDate;
- (NSInteger) daysBeforeDate: (NSDate *) aDate;
- (NSInteger)distanceInDaysToDate:(NSDate *)anotherDate;

-(double)secondsSinceStartOfDayUsingCalendar:(NSCalendar *)calendar;
-(double)hoursSinceStartOfDayUsingCalendar:(NSCalendar *)calendar;


// Decomposing dates
@property (readonly) NSInteger nearestHour;
@property (readonly) NSInteger hour;
@property (readonly) NSInteger minute;
@property (readonly) NSInteger seconds;
@property (readonly) NSInteger day;
@property (readonly) NSInteger month;
@property (readonly) NSInteger week;
@property (readonly) NSInteger weekday;
@property (readonly) NSInteger nthWeekday; // e.g. 2nd Tuesday of the month == 2
@property (readonly) NSInteger year;
@end
