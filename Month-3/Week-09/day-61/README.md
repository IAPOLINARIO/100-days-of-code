# Write a Web Crawler

Most of us are familiar with web spiders and crawlers like GoogleBot - they visit a web page, index content there, and then visit outgoing links from that page. Crawlers are an interesting technology with continuing development.

Web crawlers marry queuing and HTML parsing and form the basis of search engines etc. Writing a simple crawler is a good exercise in putting a few things together. Writing a well behaved crawler is another step up.

For this challenge you may use any single shot web client you wish, e.g. Python's httplib or any of a number of libcurl bindings; you may NOT use a crawling library like Mechanize or whatnot. You may use an HTML parsing library like BeautifulSoup; you may NOT use a headless browser like PhantomJS. The purpose of this challenge is to tie together fetching a page, reassembling links, discovering links and assembling them, adding them to a queue, managing the depth of the queue, and visiting them in some reasonable order - while avoiding duplicate visits.

Your crawler MUST support the following features:

- HTTP/1.1 client behaviors
- GET requests are the only method you must support
- Parse all links presented in HTML - anchors, images, scripts, etc
- Do not visit the same link more than once per session

Optional features include HTTPS support, support for robots.txt, support for domains to which you restrict the crawler, and storing results (for example how wget does so).

Be careful with what you crawl! Don't get yourself banned from the Internet. I highly suggest you crawl a local server you control as you may trigger rate limits and other mechanisms to identify unwanted visitors.

## Input Description

Take at least two parameters:
- a starting (seed) URL
- a maximum depth to recurse to (e.g. "1" would be fetch the HTML page and all resources like images and script associated with it but don't visit any outgoing anchor links; a depth of "2" would visit the anchor links found on that first page only, etc ...)

## Output Description

Array/vector of DISCOVERED URLs.