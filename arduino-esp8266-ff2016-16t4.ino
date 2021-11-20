#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
const char* ssid   = "Matzaptor Wi-Fi";
const char* password = "abcde12345";
const char* hostname = "ESP8266_01";
ESP8266WebServer server(80);

void initWiFi() {
	WiFi.mode(WIFI_STA);
	WiFi.hostname(hostname);
	WiFi.begin(ssid, password);
	Serial.print("Connecting to WiFi ..");
	while (WiFi.status() != WL_CONNECTED) {
		Serial.print('.');
		delay(1000);
	}
	Serial.println(WiFi.localIP());
	Serial.println(WiFi.localIP());
	Serial.println(WiFi.localIP());
	//The ESP8266 tries to reconnect automatically when the connection is lost
	WiFi.setAutoReconnect(true);
	WiFi.persistent(true);
}

#include <RCSwitch.h>
RCSwitch mySwitch = RCSwitch();

void sendCommand(unsigned long value) {
	mySwitch.send(value, 32);
}

void setup() {
	Serial.begin(9600);

	initWiFi();
	server.onNotFound(handle_NotFound);
	server.on("/", sendController);
	server.on("/toggle_fan", handle_toggle_fan);			// 3959449043
	server.on("/toggle_light", handle_toggle_light);		// 2768266707
	server.on("/light_yellow", handle_light_yellow);		// 1610638803
	server.on("/light_white", handle_light_white);			// 100689363
	server.on("/light_blue", handle_light_blue);			// 218129875
	server.on("/light_down", handle_light_down);			// 4110443987
	server.on("/light_up", handle_light_up);				// 1593861587
	server.on("/speed_1", handle_speed_1);					// 4211107283
	server.on("/speed_2", handle_speed_2);					// 4261438931
	server.on("/speed_3", handle_speed_3);					// 1509975507
	server.on("/speed_4", handle_speed_4);					// 4009780691
	server.on("/speed_5", handle_speed_5);					// 3204474323
	server.on("/reverse_fan", handle_reverse_fan);			// 4244661715
	server.on("/time_2h", handle_time_2h);					// 4143998419
	server.on("/time_4h", handle_time_4h);					// 2130732499
	server.on("/time_8h", handle_time_8h);					// 3741345235
	server.begin();

	mySwitch.enableTransmit(0); //10		// Transmitter is connected to Arduino Pin #10
	mySwitch.setProtocol(6);				// Optional set protocol (default is 1, will work for most outlets)
	mySwitch.setPulseLength(387);			// Optional set pulse length.
	//mySwitch.setRepeatTransmit(15);		// Optional set number of transmission repetitions.
}

void loop() {
	server.handleClient();
}

void handle_NotFound()			{ server.send(404, "text/plain", "404 - Not found"); }
void handle_index()				{ sendController(); }
void handle_toggle_fan()		{ sendCommand(3959449043);	handle_index(); }
void handle_toggle_light()		{ sendCommand(2768266707);	handle_index(); }
void handle_light_yellow()		{ sendCommand(1610638803);	handle_index(); }
void handle_light_white()		{ sendCommand(100689363);	handle_index(); }
void handle_light_blue()		{ sendCommand(218129875);	handle_index(); }
void handle_light_down()		{ sendCommand(4110443987);	handle_index(); }
void handle_light_up()			{ sendCommand(1593861587);	handle_index(); }
void handle_speed_1()			{ sendCommand(4211107283);	handle_index(); }
void handle_speed_2()			{ sendCommand(4261438931);	handle_index(); }
void handle_speed_3()			{ sendCommand(1509975507);	handle_index(); }
void handle_speed_4()			{ sendCommand(4009780691);	handle_index(); }
void handle_speed_5()			{ sendCommand(3204474323);	handle_index(); }
void handle_reverse_fan()		{ sendCommand(4244661715);	handle_index(); }
void handle_time_2h()			{ sendCommand(4143998419);	handle_index(); }
void handle_time_4h()			{ sendCommand(2130732499);	handle_index(); }
void handle_time_8h()			{ sendCommand(3741345235);	handle_index(); }

String controller = String("<html>")
	+ "	<head>"
	+ "		<meta charset=\"utf-8\">"
	+ "		<meta name=\"viewport\" content=\"initial-scale=1, maximum-scale=1, user-scalable=no, width=device-width\">"
	+ "		<title>FF2016-16T4</title>"
	+ "		<style>"
	+ "			* {"
	+ "				-webkit-box-sizing: border-box;"
	+ "				-moz-box-sizing: border-box;"
	+ "				box-sizing: border-box;"
	+ "			}"
	+ "			a {"
	+ "				background-color: transparent;"
	+ "				color: #337ab7;"
	+ "				text-decoration: none;"
	+ "			}"
	+ "			[role=button] {"
	+ "				cursor: pointer;"
	+ "			}"
	+ "			.btn {"
	+ "				display: inline-block;"
	+ "				padding: 6px 12px;"
	+ "				margin-bottom: 0;"
	+ "				font-size: 14px;"
	+ "				font-weight: 400;"
	+ "				line-height: 1.42857143;"
	+ "				text-align: center;"
	+ "				white-space: nowrap;"
	+ "				vertical-align: middle;"
	+ "				-ms-touch-action: manipulation;"
	+ "				touch-action: manipulation;"
	+ "				cursor: pointer;"
	+ "				-webkit-user-select: none;"
	+ "				-moz-user-select: none;"
	+ "				-ms-user-select: none;"
	+ "				user-select: none;"
	+ "				background-image: none;"
	+ "				border: 1px solid transparent;"
	+ "				border-radius: 4px;"
	+ "			}"
	+ "			.btn-default {"
	+ "				color: #333;"
	+ "				background-color: #fff;"
	+ "				border-color: #ccc;"
	+ "				margin: 2px;"
	+ "			}"
	+ "			a:active"
	+ "			,a:hover {"
	+ "				outline: 0;"
	+ "			}"
	+ "			a:focus"
	+ "			,a:hover {"
	+ "				color: #23527c;"
	+ "				text-decoration: underline;"
	+ "			}"
	+ "			a:focus {"
	+ "				outline: 5px auto -webkit-focus-ring-color;"
	+ "				outline-offset: -2px;"
	+ "			}"
	+ "			.btn.focus"
	+ "			,.btn:focus"
	+ "			,.btn:hover {"
	+ "				color: #333;"
	+ "				text-decoration: none;"
	+ "			}"
	+ "			.btn.active"
	+ "			,.btn:active {"
	+ "				background-image: none;"
	+ "				outline: 0;"
	+ "				-webkit-box-shadow: inset 0 3px 5px rgb(0 0 0 / 13%);"
	+ "				box-shadow: inset 0 3px 5px rgb(0 0 0 / 13%);"
	+ "			}"
	+ "			.btn-default.focus"
	+ "			,.btn-default:focus {"
	+ "				color: #333;"
	+ "				background-color: #e6e6e6;"
	+ "				border-color: #8c8c8c;"
	+ "			}"
	+ "			.btn-default:hover {"
	+ "				color: #333;"
	+ "				background-color: #e6e6e6;"
	+ "				border-color: #adadad;"
	+ "			}"
	+ "			.btn-default.active"
	+ "			,.btn-default:active {"
	+ "				color: #333;"
	+ "				background-color: #e6e6e6;"
	+ "				border-color: #adadad;"
	+ "			}"
	+ "			.btn-default.active"
	+ "			,.btn-default:active {"
	+ "				background-image: none;"
	+ "			}"
	+ "			.btn.active.focus"
	+ "			,.btn.active:focus"
	+ "			,.btn.focus"
	+ "			,.btn:active.focus"
	+ "			,.btn:active:focus"
	+ "			,.btn:focus {"
	+ "				outline: 5px auto -webkit-focus-ring-color;"
	+ "				outline-offset: -2px;"
	+ "			}"
	+ "			.btn-default.active.focus"
	+ "			,.btn-default.active:focus"
	+ "			,.btn-default.active:hover"
	+ "			,.btn-default:active.focus"
	+ "			,.btn-default:active:focus"
	+ "			,.btn-default:active:hover {"
	+ "				color: #333;"
	+ "				background-color: #d4d4d4;"
	+ "				border-color: #8c8c8c;"
	+ "			}"
	+ "		</style>"
	+ "	</head>"
	+ "	<body style=\"display: flex; flex-direction: column;\">"
	+ "		<a class=\"btn btn-default\" role=\"button\" href=\"./toggle_fan\">toggle_fan</a>"
	+ "		<a class=\"btn btn-default\" role=\"button\" href=\"./toggle_light\">toggle_light</a>"
	+ "		<a class=\"btn btn-default\" role=\"button\" href=\"./light_yellow\">light_yellow</a>"
	+ "		<a class=\"btn btn-default\" role=\"button\" href=\"./light_white\">light_white</a>"
	+ "		<a class=\"btn btn-default\" role=\"button\" href=\"./light_blue\">light_blue</a>"
	+ "		<a class=\"btn btn-default\" role=\"button\" href=\"./light_down\">light_down</a>"
	+ "		<a class=\"btn btn-default\" role=\"button\" href=\"./light_up\">light_up</a>"
	+ "		<a class=\"btn btn-default\" role=\"button\" href=\"./speed_1\">speed_1</a>"
	+ "		<a class=\"btn btn-default\" role=\"button\" href=\"./speed_2\">speed_2</a>"
	+ "		<a class=\"btn btn-default\" role=\"button\" href=\"./speed_3\">speed_3</a>"
	+ "		<a class=\"btn btn-default\" role=\"button\" href=\"./speed_4\">speed_4</a>"
	+ "		<a class=\"btn btn-default\" role=\"button\" href=\"./speed_5\">speed_5</a>"
	+ "		<a class=\"btn btn-default\" role=\"button\" href=\"./reverse_fan\">reverse_fan</a>"
	+ "		<a class=\"btn btn-default\" role=\"button\" href=\"./time_2h\">time_2h</a>"
	+ "		<a class=\"btn btn-default\" role=\"button\" href=\"./time_4h\">time_4h</a>"
	+ "		<a class=\"btn btn-default\" role=\"button\" href=\"./time_8h\">time_8h</a>"
	+ "	</body>"
	+ "</html>";
void sendController() { server.send(200, "text/html", controller); }