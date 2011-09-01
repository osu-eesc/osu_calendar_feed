OSU Calendar Feed:
--------------------
A Drupal 6 module

Author:
--------------------
Bryan Mayjor (mayjorb)


Description:
--------------------
creates feed ( import/update) and display of OSU calendar events for use on County/AES sites


Dependencies:
--------------------
core = "6.x"
dependencies[] = "calendar"
dependencies[] = "content_access"
dependencies[] = "date"
dependencies[] = "features"
dependencies[] = "feeds"
dependencies[] = "fieldgroup"
dependencies[] = "strongarm"
dependencies[] = "text"
dependencies[] = "views"

Installation:
--------------------
- Copy the unpacked folder "osu_calendar_feed" in your modules folder (usually [base_path]/sites/all/modules).

Usage:
--------------------
1.  After installing module locate the calendar you want to import from http://calendar.oregonstate.edu
2.  Go to http://example.com/import/calendar_feeds
3.  In the URL field enter "http://calendar.oregonstate.edu/today+90/list/[calendar shortname]/events.xml" replacing the [calendar short name] with the appropriate shortname for your calendar
4.  The module uses a modified version of the view created by the calendar module.
5.  Intended to be used with the Extension theme (which was cloned from acquia_prosper)
  

