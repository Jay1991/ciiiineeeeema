<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
<title>FPAX_TAN2000</title>
<script type="text/javascript" src="jquery-1.4.4.min.js"></script>
<script type="text/javascript" src="jq.js"></script>
<link href="style.css" rel="stylesheet" type="text/css" />
</head>
<body>

<table width="100%">
	<tr>
	  <td><h1>FPAX_TAN2000 Documentation</h1></td>
	</tr>
	<tr>
	  <td id="descr">
			<label><span>!</span> Short description</label>
			<h2>COM Server for communication with FP2000 Tanzania.<br/><hr/><br/><pre>
  OS:                                      WindowsXP and above.
  Support level:                           All commands are available.
 
 
<hr/>
  For additional problems and questions:
 
                  Mr. Nuncho Nunev:        nuncho@datecs.bg
                  Mr. Martin Naydenov:     marto@datecs.bg</pre>
			</h2>
		</td>
	</tr>
	<tr>
	  <td id="param">
			<label><span>!</span>INITIALIZATION</label>
			<div style="display: normal;">
			<table width="100%" border="1">
				<tr>
					<th width="300">Method name</th>
					<th>Short description</th>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_41_0_0.html">CMD_41_0_0</a></li></td>
					<td><pre>29h (41)	SET MEMORY SWITCHES

	Data field:	Switches
	Response:	None

	Switches	8 bytes with value 0 or 1 - the configuration switches.

	The command writes to flash memory the switches value, graphics logo, barcode height, print 
	darkness and default drawer pulse length. After RAM reset they are restored with the saved values.
	If the switches parameter is not present, then the old switches are kept.


	***********************************************************************************
	Switch		OFF					ON
	***********************************************************************************
	8		Select RS232 speed 
	7		Select RS232 speed
	6		Select RS232 speed
	5		Not used
	4		Automatic paper cutting off		Automatic paper cutting on
	3		Half cut				Full cut
	2		Obligatory Display			No Obligatory Display
	1		Normal mode				Transparent display mode
	***********************************************************************************


	*************************************
	Sw8	Sw7	Sw6	Speed	
	*************************************
	0	0	0	1200 bps
	0	0	1	2400 bps
	0	1	0	4800 bps
	0	1	1	9600 bps
	1	0	0	19200 bps
	1	0	1	38400 bps
	1	1	0	57600 bps
	1	1	1	115200 bps
	**************************************

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_61_0_0.html">CMD_61_0_0</a></li></td>
					<td><pre>3DH (61)	SETTING THE CLOCK - DATE AND HOUR

	Data field:
		TRGT_DATE	DD-MM-YY
		TRGT_TIME	HH:MM:SS
	Response:
		None

	You cannot set a date, which is earlier than the date of the last entry into the fiscal memory of device and the 
	capacity of this memory includes the year 2099. After RESET of memory, this command must be 
	executed - otherwise, the normal functioning of device cannot be resumed. 	The printer's real-time clock must 
	always be set correctly.
	Hardware limitations of the real time clock does not allow to set the seconds. After adjusting the clock seconds 
	counter will be 0!
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_72_0_0.html">CMD_72_0_0</a></li></td>
					<td><pre>48h (72)	FISCALIZATION

	Data field:	
		Serial
	Response:	
		ExitCode

	Serial	The serial number of device - it must be the number entered with command 5Bh. Status 5.3 is 
		used to verify whether the command has been successfully executed.
	
	ExitCode	Error code or 'P' symbol (when the action has been successful) is returned.

	The command will not be executed (and an error code will be set) if:
		'1'	The serial number is invalid,
		'2'	The printer has been fiscalized,
		'3'	No serial number has been programmed,
		'4'	The serial number is different from the one programmed,
		'5'	There is an opened receipt in progress,
		'6'	There are some already issued fiscal receipts or the 70 (46h) command has been executed after 
			the last daily report with closure,
		'7'	No tax rates have been entered into the memory of device,
		'8'	The tax registration number consists only of zeros,
		'9'	The clock needs setting.
	
	Fiscalization of device must be performed and after successful execution of the command, the returning of 
	printer to a "non-fiscalized" mode becomes impossible. The tax number is entered in the fiscal memory, together 
	with the current date and hour. The VAT rates are written to the fiscal memory, too. All registries are cleared 
	(to zero) after which the printer opens the first fiscal receipt, marks the moment of fiscalization on this 
	receipt and closes it.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_83_0_0.html">CMD_83_0_0</a></li></td>
					<td><pre>53h (83)	SETTING THE MULTIPLIER, DECIMALS AND DISABLED TAXES

	Data fields:	
		Multiplier
		Decimals
		EnabledSwitches
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF
	Response:		
		Multiplier
		Decimals
		Enabled
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF

	Multiplier		
			A multiplier between 0 and 3 which shows the degree of 10 before multiplying it times the 
			input or output value (at present deactivated and out of use).

	Decimals		
			One byte with a value 0 or 2 and shows the exact place of the decimal point.

	EnabledSwitches	
			6 bytes with value '0' or '1', corresponding to VAT groups 'A', 'B', 'C', 'D', 'E', 'F'. '0' means 
			disabled VAT group, '1' - enabled VAT group. 
			VAT group 'F' has to be always enabled!

	TaxX		
			The VAT rate for the corresponding VAT group in % with up to 2 decimals (0.00 to 99.00). 
			VAT group 'F' has to be always 0.00!
	
	If nothing is entered in the data field, the FP returns the currently valid values. Even when only one of the parameters 
	must be changed, the rest must be entered too. The fiscal memory has a fixed capacity for a set number of entries, 
	and for that reason the command can be performed not more than 19 times after the fiscalisation. 
	Before the fiscalisation the data are hold in RAM only and may be changed without limitations. 
	The fiscalisation command (72) makes the first such record.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_83_0_1.html">CMD_83_0_1</a></li></td>
					<td><pre>53h (83)	SETTING THE MULTIPLIER, DECIMALS AND DISABLED TAXES

	Data fields:	
		None
	Response:	
		Multiplier
		Decimals
		Enabled
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF

	Multiplier		
			A multiplier between 0 and 3 which shows the degree of 10 before multiplying it times the 
			input or output value (at present deactivated and out of use).

	Decimals		
			One byte with a value 0 or 2 and shows the exact place of the decimal point.

	EnabledSwitches	
			6 bytes with value '0' or '1', corresponding to VAT groups 'A', 'B', 'C', 'D', 'E', 'F'. '0' means 
			disabled VAT group, '1' - enabled VAT group. VAT group 'F' has to be always enabled!
	TaxX		
			The VAT rate for the corresponding VAT group in % with up to 2 decimals (0.00 to 99.00). 
			VAT group 'F' has to be always 0.00!
	
	If nothing is entered in the data field, the FP returns the currently valid values. Even when only one of the 
	parameters must be changed, the rest must be entered too. The fiscal memory has a fixed capacity for a set 
	number of entries, and for that reason the command can be performed not more than 19 times after the fiscalisation. 
	Before the fiscalisation the data are hold in RAM only and may be changed without limitations. The fiscalisation 
	command (72) makes the first such record.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_85_0_0.html">CMD_85_0_0</a></li></td>
					<td><pre>55H (85)	DEFINE ADDITIONAL PAYMENT TYPES NAME

	Data field: 
		Option
		INPUT_NAME
	Response:	
		FP_Result
		OUTPUT_NAME

	Option:
		'I'	Additional payment 1
		'J'	Additional payment 2
		'K'	Additional payment 3
		'L'	Additional payment 4

	INPUT_NAME	Comment text of the payment. Up to 24 bytes. If not present, the current name 
			is returned.

	Result	One byte:
		'P'	No error.
		'F'	INPUT_NAME longer than 24 bytes.
	OUTPUT_NAME	Comment text) of the payment. Up to 24 bytes.

	The command defines the comment text, printed before the additional (programmable) payments. 
	The command is not permitted after the first fiscal receipt for the day.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_85_0_1.html">CMD_85_0_1</a></li></td>
					<td><pre>55H (85)	DEFINE ADDITIONAL PAYMENT TYPES NAME

	Data field: 
		Option
	Response:	 
		FP_Result|OUTPUT_NAME

	Option:
		'I'	Additional payment 1
		'J'	Additional payment 2
		'K'	Additional payment 3
		'L'	Additional payment 4
		

	Result	One byte:
		'P'	No error.
		'F'	INPUT_NAME longer than 24 bytes.
	OUTPUT_NAME	Comment text) of the payment. Up to 24 bytes.

	The current name is returned.
	The command is not permitted after the first fiscal receipt for the day.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_91_0_0.html">CMD_91_0_0</a></li></td>
					<td><pre>5Bh (91)	PROGRAMMING THE SERIAL

	Data field:	
		Serial
	Response:		
		FP_Result
		CountryStr

	Serial
		The serial number. 10 symbols - 2 digits, 2 letters and 6 digits in this order.
	
	FP_Result		
		One byte.  
		'P' - OK; 
		'F' - errors.

	CountryStr	
		The name of country. 
		For example: "TANZANIA"
	
	The serial number is entered and written to the fiscal memory. It cannot be changed anymore. 
	The printer must be turned off to recognize a new EJ Card.
	If Result = 'F' and the S1.1 flag is raised, the command has not been successful because either the 
	fiscal memory has not been formatted or the serial number has already been entered.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_98_0_0.html">CMD_98_0_0</a></li></td>
					<td><pre>62h (98)	SETTING THE TAX REGISTRATION NUMBER

	Data field:	
		TIN
		VRN
	Response:	
		None

	TIN	The TAX identification number as a text (9 bytes).
	VRN	The VAT identification number as a text (9 bytes).</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_101_0_0.html">CMD_101_0_0</a></li></td>
					<td><pre>65h (101)	SETTING THE OPERATOR'S PASSWORD

	Data field:	
		OpCode
		OldPwd
		NewPwd
	Response:	
		None

	OpCode	
		Operator's code (1 to 16)

	OldPwd	
		Old password (4 to 8 digits)

	NewPwd	
		New password (4 to 8 digits)

Sets one of the 16 operator's passwords, which will be demanded upon opening a fiscal receipt. After three 
erroneous password entries, the printer will block, it must then be switched OFF and ON again to continue 
operating.
After initialization or reset of the operational memory, all 16 passwords are "0000".</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_102_0_0.html">CMD_102_0_0</a></li></td>
					<td><pre>66h (102)	ENTERING OPERATOR'S NAME

	Data field:	
		OpCode
		Pwd
		OpName
	Response:	
		None

	OpCode	
		Operator's code (1 to 16)

	Pwd	
		Password (4 to 6 digits)

	OpName	
		Name of the operator (up to 24 symbols)

Enters one of the 16 operator names. The number and name of the operator are printed at the beginning of each 
fiscal (clients) receipt. 
After three erroneous password entries, the printer will block, it must then be switched OFF and ON again 
to continue operating. After initialization or reset of the operational memory, all 16 password locations are empty.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_0_0.html">CMD_107_0_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS

	Articles information

	Data field:		
		None
	Response:		
		ErrorCode
		Total
		Prog
		Len

	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command

	Total		Total programmable article count (3000 for this printer).
	Progr		Programmed article count.
	Len		Maximal article name length (36 for this printer).</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_1_0.html">CMD_107_1_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS

Programming an item

Up to 3000 different items may be programmed and the command will be rejected if a similar item has already 
been programmed in the memory of printer and sales of this item have been registered. An item with zero 
accumulated sums is subject to change. The number of the free items is returned after an ErrorCode parameter.

	Data field:	
		TaxGr
		PLU
		Group
		SPrice
		Replace
		Quantity
		ItemName
	Response:	
		ErrorCode,FreeItemsNumber


	TaxGr	
		Tax group. One byte ('A', 'B', 'C', 'D', 'E' or 'F').
	PLU	
		Number of the item (1 to 999999999)
	Group	
		Article group (1 - 99).
	SPrice	
		Singular price - up to 8 meaningful digits.
	Replace	
		One byte with value 'A'. Changes the meaning of the next parameter (Quantity).
	Quantity	
		A number with up to 3 decimals - the available quantity of the article. If Replace is 
		present, then the available quantity is replaced with this parameter, otherwise it is added 
		to the old value (if the article is already programmed, of course). Every sale command of 
		this article will decrease this value.
	ItemName	
		Name of the item - up to 36 bytes.


	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command
	FreeItemsNumber	
		The number of the free items is returned after an ErrorCode parameter.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_2_0.html">CMD_107_2_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS

Change the quantity of an item
Changing the quantity is possible, if the article is programmed.

	Data field:	
		PLU
		Quantity
	Response:	
		ErrorCode

	PLU
		Article number (1 to 999999999).
	Quantity	
		Quantity correction - a floating-point number with 3 decimal places. Positive number 
		increases the available quantity, negative decreases it.


	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
		'P'	Successful command
		'F'	Unsuccessful command


</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_3_0.html">CMD_107_3_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS

Change the price of an item
Changing the price if possible, if the article is programmed and no sales of this article are made in the 
fiscal receipt (if a fiscal receipt is open).

	Data field:	
		PLU
		Sprice
	Response:	
		ErrorCode


	PLU	Article number (1 to 999999999).
	SPrice	Singular price - up to 8 meaningful digits.



	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
		'P'	Successful command
		'F'	Unsuccessful command


</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_4_0.html">CMD_107_4_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS

	Delete all items with non-zero accumulated sums.

	Data field:	
		None
	Response:	
		ErrorCode


	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
		'P'	Successful command
		'F'	Unsuccessful command

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_4_1.html">CMD_107_4_1</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS

	Delete all items with non-zero accumulated sums.

	Data field:	
		PLU
	Response:	
		ErrorCode

	PLU
		Deletes article with selected number if there are no accumulated sums.

	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
		'P'	Successful command
		'F'	Unsuccessful command</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_4_2.html">CMD_107_4_2</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS

	Delete all items with non-zero accumulated sums.

	Data field:	
		PLU1
		PLU2
	Response:	
		ErrorCode

	PLU1
	PLU2	
		Deletes the articles within a set interval which do not have accumulated sums.

	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
		'P'	Successful command
		'F'	Unsuccessful command</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_5_0.html">CMD_107_5_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS


	Reading Item data

	Data field:	
		PLU
	Response:	
		ErrorCode
		PLU
		TaxGr
		Group
		SPrice
		Total
		Sold
		Available
		ItemName


	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command	

	PLU	
		Individual number of the item. 9 digits (000000001 to 999999999)
	TaxGr	
		Tax group - 1 byte
	Group	
		Article group. 2 digits (01 - 99).
	SPrice	
		Singular price. A floating-point number - decimal places depend on the count set 
		using command 83 (53h).
	Total	Accumulated sum for this article.
	Sold	Accumulated quantity - a floating-point number with 3 decimal places.
	Available	Available quantity of this article.
	ItemName	The name of the item. Up to 36 symbols.
	
If the item cannot be found, one 'F' byte is returned.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_6_0.html">CMD_107_6_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS


	Returning the data on the first found programmed item. 
	ANSWER_PLU is the first programmed article with number greater than or equal to PLU.

	Data field:	
		PLU
	Response:
		ErrorCode
		PLU
		TaxGr
		Group
		SPrice
		Total
		Sold
		Available
		ItemName


	ErrorCode
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command	

	ANSWER_PLU	
		Individual number of the item. 9 digits (000000001 to 999999999)

	TaxGr
		Tax group - 1 byte

	Group
		Article group. 2 digits (01 - 99).
	SPrice
		Singular price. A floating-point number - decimal places depend on the count set 
		using command 83 (53h).
	Total
		Accumulated sum for this article.
	Sold
		Accumulated quantity - a floating-point number with 3 decimal places.
	Available
		Available quantity of this article.
	ItemName
		The name of the item. Up to 36 symbols.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_7_0.html">CMD_107_7_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS


	Returning the data on the programmed item with the greatest number.
	ANSWER_PLU is the first programmed article with number lower than or equal to PLU is 
	returned. 

	Data field:	
		PLU
	Response:	
		ErrorCode
		PLU
		TaxGr
		Group
		SPrice
		Total
		Sold
		Available
		ItemName


	ErrorCode
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command	



	ANSWER_PLU
			Individual number of the item. 9 digits (000000001 to 999999999)

	TaxGr		
			Tax group - 1 byte

	Group		
			Article group. 2 digits (01 - 99).

	SPrice		
		Singular price. A floating-point number - decimal places depend on the count set
		using command 83 (53h).

	Total		
		Accumulated sum for this article.

	Sold	
		Accumulated quantity - a floating-point number with 3 decimal places.

	Available	
		Available quantity of this article.

	ItemName	
		The name of the item. Up to 36 symbols.

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_8_0.html">CMD_107_8_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS


Returning the data on the next found programmed item.
Depending of the starting subcommand ('First (CMD_107_6_0)' or 'Last (CMD_107_7_0)'), the articles 
are enumerated in ascending or descending order.

	Data field:
		PLU
	Response:	
		ErrorCode
		PLU
		TaxGr
		Group
		SPrice
		Total
		Sold
		Available
		ItemName


	ErrorCode
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command	

	ANSWER_PLU	
		Individual number of the item. 9 digits (000000001 to 999999999)

	TaxGr
		Tax group - 1 byte

	Group
		Article group. 2 digits (01 - 99).

	SPrice
		Singular price. A floating-point number - decimal places depend on the count set 
		using command 83 (53h).

	Total
		Accumulated sum for this article.

	Sold
		Accumulated quantity - a floating-point number with 3 decimal places.

	Available
		Available quantity of this article.

	ItemName
		The name of the item. Up to 36 symbols.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_9_0.html">CMD_107_9_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS


	Returning the data on the first sold item.
	ANSWER_PLU is the first sold article with number greater than or equal to PLU is returned. 

	Data field:	
		PLU
	Response:	
		ErrorCode
		PLU
		TaxGr
		Group
		SPrice
		Total
		Sold
		Available
		ItemName


	ErrorCode
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command	

	ANSWER_PLU
		Individual number of the item. 9 digits (000000001 to 999999999)

	TaxGr
		Tax group - 1 byte

	Group
		Article group. 2 digits (01 - 99).

	SPrice
		Singular price. A floating-point number - decimal places depend on the count set 
		using command 83 (53h).

	Total
		Accumulated sum for this article.
	Sold
		Accumulated quantity - a floating-point number with 3 decimal places.

	Available
		Available quantity of this article.

	ItemName	
		The name of the item. Up to 36 symbols.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_10_0.html">CMD_107_10_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS


Returning the data on the sold item with the greatest number.
ANSWER_PLU is the first sold article with number lower than or equal to PLU is returned.

	Data field:	
		PLU
	Response:	
		ErrorCode
		PLU
		TaxGr
		Group
		SPrice
		Total
		Sold
		Available
		ItemName


	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command	

	ANSWER_PLU	
		Individual number of the item. 9 digits (000000001 to 999999999)

	TaxGr
		Tax group - 1 byte

	Group
		Article group. 2 digits (01 - 99).

	SPrice
		Singular price. A floating-point number - decimal places depend on the count set 
		using command 83 (53h).

	Total
		Accumulated sum for this article.

	Sold
		Accumulated quantity - a floating-point number with 3 decimal places.

	Available
		Available quantity of this article.

	ItemName	
		The name of the item. Up to 36 symbols.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_11_0.html">CMD_107_11_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS


Returning the data on the next found sold item.
Depending of the starting subcommand ('First (CMD_107_9_0)' or 'Last (CMD_107_10_0)'), the 
articles are enumerated in ascending or descending order.

	Data field:	
		PLU
	Response:	
		ErrorCode
		PLU
		TaxGr
		Group
		SPrice
		Total
		Sold
		Available
		ItemName


	ErrorCode
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command	
	ANSWER_PLU
		Individual number of the item. 9 digits (000000001 to 999999999)

	TaxGr	
		Tax group - 1 byte

	Group
		Article group. 2 digits (01 - 99).

	SPrice
		Singular price. A floating-point number - decimal places depend on the count set 
		using command 83 (53h).

	Total
		Accumulated sum for this article.

	Sold
		Accumulated quantity - a floating-point number with 3 decimal places.

	Available
		Available quantity of this article.

	ItemName	
		The name of the item. Up to 36 symbols.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_12_0.html">CMD_107_12_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS


Returning the data on the first free item.
ANSWER_PLU is the first free (not programmed) article with number greater than or equal to PLU is 
returned.

	Data field:	
		PLU
	Response:	
		ErrorCode
		ANSWER_PLU


	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command	
	ANSWER_PLU	
		Individual number of the item. 9 digits (000000001 to 999999999)</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_12_1.html">CMD_107_12_1</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS


Returning the data on the last free item.
ANSWER_PLU is the first free (not programmed) article with number lower than or equal to PLU is 
returned.

	Data field:	
		PLU
	Response:	
		ErrorCode
		ANSWER_PLU


	ErrorCode
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command	
	ANSWER_PLU
		Individual number of the item. 9 digits (000000001 to 999999999)</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_115_0.html">CMD_115_0</a></li></td>
					<td><pre>73h (115)	PROGRAMMING A GRAPHIC LOGO

	Data field:	
		RowNum
		RowData

	Response:
		None

	RowNum		Shows the line, which is being programmed - a number 
			between 0 and 95
	RowData		Graphic data. Two symbols for each byte of information are 
			entered in the hexadecimal code. The length of the data is 
			up to 72 bytes, and if they are less, an automatic addition 
			of "00" follows.
	
This command offers the option to define a graphic logo with dimensions 
72 x 12 mm (576 x 96 dots) designed by the user themselves. 

The printing of this logo is activated with command 43. It is printed out immediately before 
the HEADER - at the beginning of each fiscal or non-fiscal receipt. In order to define the whole 
logo, the command must be executed 96 times - once for each line. After RESET of memory, 
default logo is active.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_115_1.html">CMD_115_1</a></li></td>
					<td><pre>73h (115)	PROGRAMMING A GRAPHIC LOGO

	Data field:	
		RowNum

	Response:	
		RowData

	RowNum		Shows the line, which is being programmed - a number 
			between 0 and 95
	RowData		Graphic data. Two symbols for each byte of information are 
			entered in the hexadecimal code. The length of the data is 
			up to 72 bytes, and if they are less, an automatic addition of 
			"00" follows.
	
This command offers the option to define a graphic logo with dimensions 
72 x 12 mm (576 x 96 dots) designed by the user themselves. 
The printing of this logo is activated with command 43. It is printed out immediately before 
the HEADER - at the beginning of each fiscal or 
non-fiscal receipt. In order to define the whole logo, the command must be executed 96 times - 
once for each line. After RESET of memory, default logo is active.</pre></td>
				</tr>
			</table>
			</div>
		</td>
	</tr>
	<tr>
	  <td id="param">
			<label><span>!</span>SALES</label>
			<div style="display: normal;">
			<table width="100%" border="1">
				<tr>
					<th width="300">Method name</th>
					<th>Short description</th>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_38_0_0.html">CMD_38_0_0</a></li></td>
					<td><pre>26h (38)	Open a non-fiscal receipt.

The FP performs the following actions:
	-	Prints the header
	-	Prints the tax registration number of the seller
	-	A response is received, which contains Allreceipt
The command cannot be executed, S1.1 is raised if.
	-	The fiscal memory has not been formatted
	-	There is an opened fiscal or non-fiscal receipt
	-	There is no paper
	-	The clock is not set
	-	The electronic journal is full

	Data field:
		None
	Response:	
		RecCnt
		GlobRecCnt

	RecCnt		Non-fiscal receipt count since last Z-report (4 bytes).
	GlobRecCnt	Global non-fiscal receipt count (after the fiscalisation) (8 bytes).

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_39_0_0.html">CMD_39_0_0</a></li></td>
					<td><pre>27h (39)	Closing a non-fiscal receipt


The FP performs the following actions:
Prints the footer
The sequence number, date and hour of document are printed
** NON-FISCAL RECEIPT **  is printed in expanded style.
If the S1.1 flag is raised, the command is not executed because there is no opened non-fiscal receipt.


	Data field:
			None
	Response:	
			RecCnt
			GlobRecCnt

	RecCnt		Non-fiscal receipt count since last Z-report (4 bytes).
	GlobRecCnt	Global non-fiscal receipt count (after the fiscalisation) (8 bytes).</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_42_0_0.html">CMD_42_0_0</a></li></td>
					<td><pre>2Ah (42)	PRINTING OF A FREE NON-FISCAL TEXT
	
If S1.1 is raised, there is no non-fiscal receipt opened and the text is not printed.

	
	Data field:	Text
	Response:	None

	Text	A text of 42 symbols (at most). The symbols after 36 are cut off.

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_48_0_0.html">CMD_48_0_0</a></li></td>
					<td><pre>30h (48)	OPENING A FISCAL CLIENT'S RECEIPT

	Data field:
			OpCode
			OpPwd
			TillNmb
	Response:		
			RecCnt
			GlobRecCnt

	OpCode		Operator's number (1 to 16)
	OpPwd		Operator's password (4 to 8 digits)
	TillNmb		Number of point of sale (a whole number of maximum 5 digits)

	RecCnt		Fiscal receipt count since last Z-report (4 bytes).
	GlobRecCnt	Global fiscal receipt count (after the fiscalisation) (8 bytes).




The FP performs the following actions:
	Prints the HEADER
	Prints the tax registration number
	Prints the number and name of operator as well as the cashier desk number
	RecCnt and GlobRecCnt are returned 

The command will not be successful if:
	There is an opened fiscal or non-fiscal receipt
	The maximum number of receipts, as fixed for the day, has already been issued
	The fiscal memory is full
	The fiscal memory is damaged
	No code or operator password, or cashier desk number available
	The HEADER is not programmed
	No tax registration number available
	Wrong operator password
	The clock needs setting
	Journal is full
	After entering three wrong operator's passwords, the printer blocks and must be switched 
	off and on again to restart operation.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_49_0_0.html">CMD_49_0_0</a></li></td>
					<td><pre>31H (49)	REGISTRATION OF SALES

	Data field:
		TaxCd
		Price

	Response:	
		None



	TaxCd	One byte containing letter, which indicates the type of tax. There is a restriction, depending on the enabled 
		tax groups (command 83).
	Price	This is a singular price that consists of 8 meaningful digits. 

	

	FP performs the following actions:
		-	The text, describing sale is printed out together with the price and code of discount or surcharge. 
			If there is a set quantity, the information on it is printed out too.
		-	The price of the items sold is accumulated to the sums already stored in the operational memory. 
			In case of memory overflow the value of respective bites of the status field will be set.
		-	If there is a discount or surcharge, it is printed out on a separate line and is then added to a specially 
			maintained registers within the printer. 
			The values for the day are printed out together with the daily financial report.

	The command will not be correctly executed if and when:
		-	No fiscal receipt has been opened
		-	The maximum number of sales for one receipt have already been performed (512)
		-	The 35h command has been successfully executed
		-	The sum for some of the tax groups has become negative
		-	The sum of discounts and surcharges within the same receipt has become negative
		-	Journal is full
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_49_0_1.html">CMD_49_0_1</a></li></td>
					<td><pre>31H (49)	REGISTRATION OF SALES

	Data field:
		L1
		L2
		TaxCd
		Price
		Quan
		UN
		Perc

	Response:
		None

	L1	A text of up to 36 bytes containing one line of description of sale.
	L2	A text of up to 36 bytes containing a second line describing the sale.
	TaxCd	One byte containing letter, which indicates the type of tax. There is a restriction, depending on the enabled 
		tax groups (command 83).
	Price	This is a singular price that consists of 8 meaningful digits. 
	Quan	A non-mandatory parameter setting the quantity of items for sale. By default, this is 1.000.The length of this 
		parameter is 8 meaningful digits (not more than 3 after the decimal point). The result Price*Quan is rounded 
		up to the set number of digits and cannot be longer than 8 meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	Perc	This is a non-mandatory parameter which sets the value of discount or surcharge (depending on the sign) in 
		percent over the currently performed sale. Possible values are between - 99.00% and 99.00%, where up to 2 
		decimal places are acceptable.
	


	FP performs the following actions:
		-	The text, describing sale is printed out together with the price and code of discount or surcharge. 
			If there is a set quantity, the information on it is printed out too.
		-	The price of the items sold is accumulated to the sums already stored in the operational memory. 
			In case of memory overflow the value of respective bites of the status field will be set.
		-	If there is a discount or surcharge, it is printed out on a separate line and is then added to a specially 
			maintained registers within the printer. 
			The values for the day are printed out together with the daily financial report.

	The command will not be correctly executed if and when:
		-	No fiscal receipt has been opened
		-	The maximum number of sales for one receipt have already been performed (512)
		-	The 35h command has been successfully executed
		-	The sum for some of the tax groups has become negative
		-	The sum of discounts and surcharges within the same receipt has become negative
		-	Journal is full
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_49_0_2.html">CMD_49_0_2</a></li></td>
					<td><pre>31H (49)	REGISTRATION OF SALES

	Data field:
		L1
		L2
		TaxCd
		Price
		Quan
		UN
		AbsSum
	Response:	
		None

	L1	A text of up to 36 bytes containing one line of description of sale.
	L2	A text of up to 36 bytes containing a second line describing the sale.
	TaxCd	One byte containing letter, which indicates the type of tax. There is a restriction, depending on the enabled 
		tax groups (command 83).
	Price	This is a singular price that consists of 8 meaningful digits. 
	Quan	A non-mandatory parameter setting the quantity of items for sale. By default, this is 1.000.The length of this 
		parameter is 8 meaningful digits (not more than 3 after the decimal point). The result Price*Quan is rounded 
		up to the set number of digits and cannot be longer than 8 meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	AbsSum	This is a non-mandatory parameter which sets the value of discount or surcharge (depending on the sign) over 
		the currently performed sale. Up to 8 significant digits.
	


	FP performs the following actions:
		-	The text, describing sale is printed out together with the price and code of discount or surcharge. 
			If there is a set quantity, the information on it is printed out too.
		-	The price of the items sold is accumulated to the sums already stored in the operational memory. 
			In case of memory overflow the value of respective bites of the status field will be set.
		-	If there is a discount or surcharge, it is printed out on a separate line and is then added to a specially 
			maintained registers within the printer. 
			The values for the day are printed out together with the daily financial report.

	The command will not be correctly executed if and when:
		-	No fiscal receipt has been opened
		-	The maximum number of sales for one receipt have already been performed (512)
		-	The 35h command has been successfully executed
		-	The sum for some of the tax groups has become negative
		-	The sum of discounts and surcharges within the same receipt has become negative
		-	Journal is full
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_49_0_3.html">CMD_49_0_3</a></li></td>
					<td><pre>31H (49)	REGISTRATION OF SALES

	Data field:
		L1
		TaxCd
		Price
		Quan
		UN
		AbsSum

	Response:
		None

	L1	A text of up to 36 bytes containing one line of description of sale.
	TaxCd	One byte containing letter, which indicates the type of tax. There is a restriction, depending on the enabled 
		tax groups (command 83).
	Price	This is a singular price that consists of 8 meaningful digits. 
	Quan	A non-mandatory parameter setting the quantity of items for sale. By default, this is 1.000.The length of this 
		parameter is 8 meaningful digits (not more than 3 after the decimal point). The result Price*Quan is rounded 
		up to the set number of digits and cannot be longer than 8 meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	AbsSum	This is a non-mandatory parameter which sets the value of discount or surcharge (depending on the sign) over 
		the currently performed sale. Up to 8 significant digits.
	


	FP performs the following actions:
		-	The text, describing sale is printed out together with the price and code of discount or surcharge. 
			If there is a set quantity, the information on it is printed out too.
		-	The price of the items sold is accumulated to the sums already stored in the operational memory. 
			In case of memory overflow the value of respective bites of the status field will be set.
		-	If there is a discount or surcharge, it is printed out on a separate line and is then added to a specially 
			maintained registers within the printer. 
			The values for the day are printed out together with the daily financial report.

	The command will not be correctly executed if and when:
		-	No fiscal receipt has been opened
		-	The maximum number of sales for one receipt have already been performed (512)
		-	The 35h command has been successfully executed
		-	The sum for some of the tax groups has become negative
		-	The sum of discounts and surcharges within the same receipt has become negative
		-	Journal is full
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_49_0_4.html">CMD_49_0_4</a></li></td>
					<td><pre>31H (49)	REGISTRATION OF SALES

	Data field:
		TaxCd
		Price
		Quan
		UN
		AbsSum
	Response:	
		None



	TaxCd	One byte containing letter, which indicates the type of tax. There is a restriction, depending on the enabled 
		tax groups (command 83).
	Price	This is a singular price that consists of 8 meaningful digits. 
	Quan	A non-mandatory parameter setting the quantity of items for sale. By default, this is 1.000.The length of this 
		parameter is 8 meaningful digits (not more than 3 after the decimal point). The result Price*Quan is rounded 
		up to the set number of digits and cannot be longer than 8 meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	AbsSum	This is a non-mandatory parameter which sets the value of discount or surcharge (depending on the sign) over 
		the currently performed sale. Up to 8 significant digits.
	


	FP performs the following actions:
		-	The text, describing sale is printed out together with the price and code of discount or surcharge. 
			If there is a set quantity, the information on it is printed out too.
		-	The price of the items sold is accumulated to the sums already stored in the operational memory. 
			In case of memory overflow the value of respective bites of the status field will be set.
		-	If there is a discount or surcharge, it is printed out on a separate line and is then added to a specially 
			maintained registers within the printer. 
			The values for the day are printed out together with the daily financial report.

	The command will not be correctly executed if and when:
		-	No fiscal receipt has been opened
		-	The maximum number of sales for one receipt have already been performed (512)
		-	The 35h command has been successfully executed
		-	The sum for some of the tax groups has become negative
		-	The sum of discounts and surcharges within the same receipt has become negative
		-	Journal is full
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_49_0_5.html">CMD_49_0_5</a></li></td>
					<td><pre>31H (49)	REGISTRATION OF SALES

	Data field:
		L2
		TaxCd
		Price
		Quan
		UN
		AbsSum
	Response:	
		None


	L2	A text of up to 36 bytes containing a second line describing the sale.
	TaxCd	One byte containing letter, which indicates the type of tax. There is a restriction, depending on the enabled 
		tax groups (command 83).
	Price	This is a singular price that consists of 8 meaningful digits. 
	Quan	A non-mandatory parameter setting the quantity of items for sale. By default, this is 1.000.The length of this 
		parameter is 8 meaningful digits (not more than 3 after the decimal point). The result Price*Quan is rounded 
		up to the set number of digits and cannot be longer than 8 meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	AbsSum	This is a non-mandatory parameter which sets the value of discount or surcharge (depending on the sign) 
		over the currently performed sale. Up to 8 significant digits.
	


	FP performs the following actions:
		-	The text, describing sale is printed out together with the price and code of discount or surcharge. 
			If there is a set quantity, the information on it is printed out too.
		-	The price of the items sold is accumulated to the sums already stored in the operational memory. 
			In case of memory overflow the value of respective bites of the status field will be set.
		-	If there is a discount or surcharge, it is printed out on a separate line and is then added to a specially 
			maintained registers within the printer. 
			The values for the day are printed out together with the daily financial report.

	The command will not be correctly executed if and when:
		-	No fiscal receipt has been opened
		-	The maximum number of sales for one receipt have already been performed (512)
		-	The 35h command has been successfully executed
		-	The sum for some of the tax groups has become negative
		-	The sum of discounts and surcharges within the same receipt has become negative
		-	Journal is full
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_49_0_6.html">CMD_49_0_6</a></li></td>
					<td><pre>31H (49)	REGISTRATION OF SALES

	Data field:
		L1
		TaxCd
		Price
		Quan
		UN
		Perc
	Response:	
		None

	L1	A text of up to 36 bytes containing one line of description of sale.
	TaxCd	One byte containing letter, which indicates the type of tax. There is a restriction, depending on the enabled 
		tax groups (command 83).
	Price	This is a singular price that consists of 8 meaningful digits. 
	Quan	A non-mandatory parameter setting the quantity of items for sale. By default, this is 1.000.The length of this 
		parameter is 8 meaningful digits (not more than 3 after the decimal point). The result Price*Quan is rounded 
		up to the set number of digits and cannot be longer than 8 meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	Perc	This is a non-mandatory parameter which sets the value of discount or surcharge (depending on the sign) in 
		percent over the currently performed sale. Possible values are between - 99.00% and 99.00%, where up to 2 
		decimal places are acceptable.
	


	FP performs the following actions:
		-	The text, describing sale is printed out together with the price and code of discount or surcharge. 
			If there is a set quantity, the information on it is printed out too.
		-	The price of the items sold is accumulated to the sums already stored in the operational memory. 
			In case of memory overflow the value of respective bites of the status field will be set.
		-	If there is a discount or surcharge, it is printed out on a separate line and is then added to a specially 
			maintained registers within the printer. 
			The values for the day are printed out together with the daily financial report.

	The command will not be correctly executed if and when:
		-	No fiscal receipt has been opened
		-	The maximum number of sales for one receipt have already been performed (512)
		-	The 35h command has been successfully executed
		-	The sum for some of the tax groups has become negative
		-	The sum of discounts and surcharges within the same receipt has become negative
		-	Journal is full
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_49_0_7.html">CMD_49_0_7</a></li></td>
					<td><pre>31H (49)	REGISTRATION OF SALES

	Data field:
		L2
		TaxCd
		Price
		Quan
		UN
		Perc
	Response:
		None


	L2	A text of up to 36 bytes containing a second line describing the sale.
	TaxCd	One byte containing letter, which indicates the type of tax. There is a restriction, depending on the enabled 
		tax groups (command 83).
	Price	This is a singular price that consists of 8 meaningful digits. 
	Quan	A non-mandatory parameter setting the quantity of items for sale. By default, this is 1.000.The length of this 
		parameter is 8 meaningful digits (not more than 3 after the decimal point). The result Price*Quan is rounded 
		up to the set number of digits and cannot be longer than 8 meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	Perc	This is a non-mandatory parameter which sets the value of discount or surcharge (depending on the sign) in 
		percent over the currently performed sale. Possible values are between - 99.00% and 99.00%, where up to 2 
		decimal places are acceptable.
	


	FP performs the following actions:
		-	The text, describing sale is printed out together with the price and code of discount or surcharge. 
			If there is a set quantity, the information on it is printed out too.
		-	The price of the items sold is accumulated to the sums already stored in the operational memory. 
			In case of memory overflow the value of respective bites of the status field will be set.
		-	If there is a discount or surcharge, it is printed out on a separate line and is then added to a specially 
			maintained registers within the printer. 
			The values for the day are printed out together with the daily financial report.

	The command will not be correctly executed if and when:
		-	No fiscal receipt has been opened
		-	The maximum number of sales for one receipt have already been performed (512)
		-	The 35h command has been successfully executed
		-	The sum for some of the tax groups has become negative
		-	The sum of discounts and surcharges within the same receipt has become negative
		-	Journal is full
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_49_0_8.html">CMD_49_0_8</a></li></td>
					<td><pre>31H (49)	REGISTRATION OF SALES

	Data field:
		TaxCd
		Price
		Quan
		UN
		Perc
	Response:	
		None


	TaxCd	One byte containing letter, which indicates the type of tax. There is a restriction, depending on the enabled 
		tax groups (command 83).
	Price	This is a singular price that consists of 8 meaningful digits. 
	Quan	A non-mandatory parameter setting the quantity of items for sale. By default, this is 1.000.The length of this 
		parameter is 8 meaningful digits (not more than 3 after the decimal point). The result Price*Quan is rounded 
		up to the set number of digits and cannot be longer than 8 meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	Perc	This is a non-mandatory parameter which sets the value of discount or surcharge (depending on the sign) in 
		percent over the currently performed sale. Possible values are between - 99.00% and 99.00%, where up to 2
		decimal places are acceptable.
	


	FP performs the following actions:
		-	The text, describing sale is printed out together with the price and code of discount or surcharge. 
			If there is a set quantity, the information on it is printed out too.
		-	The price of the items sold is accumulated to the sums already stored in the operational memory. 
			In case of memory overflow the value of respective bites of the status field will be set.
		-	If there is a discount or surcharge, it is printed out on a separate line and is then added to a specially 
			maintained registers within the printer. 
			The values for the day are printed out together with the daily financial report.

	The command will not be correctly executed if and when:
		-	No fiscal receipt has been opened
		-	The maximum number of sales for one receipt have already been performed (512)
		-	The 35h command has been successfully executed
		-	The sum for some of the tax groups has become negative
		-	The sum of discounts and surcharges within the same receipt has become negative
		-	Journal is full
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_51_0_0.html">CMD_51_0_0</a></li></td>
					<td><pre>33h (51)	SUBTOTAL
	
	Data field:
		Print
		Display
	Response:	
		SubTotal
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF

	ToPrint	One byte, which if '1' the sum of the subtotal will be printed out.
	Display	One byte which if '1' the sum of the subtotal will appear on display.

	SubTotal	The sum accumulated for the current fiscal receipt (10 bytes).
	TaxA	The sum over tax group A /10 bytes/
	TaxB	The sum over tax group B /10 bytes/
	TaxC	The sum over tax group C /10 bytes/
	TaxD	The sum over tax group D /10 bytes/
	TaxE	The sum over tax group E /10 bytes/
	TaxF	The sum over tax group F /10 bytes/
	
The sum of all sales registered in the fiscal receipt is calculated. If necessary, the sum may be printed out and/or 
brought out on display. 

The calculated total sum and the accumulated separate sums for each tax group are returned to the PC. 
If a discount or surcharge is entered, it is printed out on a separate line and the accumulated sums over the different 
tax groups are respectively corrected.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_51_0_1.html">CMD_51_0_1</a></li></td>
					<td><pre>33h (51)	SUBTOTAL
	
	Data field:
		Print
		Display
		Perc
	Response:	
		SubTotal
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF

	ToPrint	One byte, which if '1' the sum of the subtotal will be printed out.
	Display	One byte which if '1' the sum of the subtotal will appear on display.
	Perc	Shows the value of discount or surcharge in percent over the sum accumulated so far.

	SubTotal	The sum accumulated for the current fiscal receipt (10 bytes).
	TaxA	The sum over tax group A /10 bytes/
	TaxB	The sum over tax group B /10 bytes/
	TaxC	The sum over tax group C /10 bytes/
	TaxD	The sum over tax group D /10 bytes/
	TaxE	The sum over tax group E /10 bytes/
	TaxF	The sum over tax group F /10 bytes/
	
The sum of all sales registered in the fiscal receipt is calculated. If necessary, the sum may be printed out and/or 
brought out on display. 

The calculated total sum and the accumulated separate sums for each tax group are returned to the PC. 

If a discount or surcharge is entered, it is printed out on a separate line and the accumulated sums over the different 
tax groups are respectively corrected.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_51_0_2.html">CMD_51_0_2</a></li></td>
					<td><pre>33h (51)	SUBTOTAL
	
	Data field:
		Print
		Display
		AbsSum
	Response:	
		SubTotal
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF

	ToPrint	One byte, which if '1' the sum of the subtotal will be printed out.
	Display	One byte which if '1' the sum of the subtotal will appear on display.
	AbsSum	A non-mandatory parameter, which shows the value of discount as absolute value (up to 8 digits).

	SubTotal	The sum accumulated for the current fiscal receipt (10 bytes).
	TaxA	The sum over tax group A /10 bytes/
	TaxB	The sum over tax group B /10 bytes/
	TaxC	The sum over tax group C /10 bytes/
	TaxD	The sum over tax group D /10 bytes/
	TaxE	The sum over tax group E /10 bytes/
	TaxF	The sum over tax group F /10 bytes/
	
The sum of all sales registered in the fiscal receipt is calculated. If necessary, the sum may be printed out and/or brought out 
on display. 

The calculated total sum and the accumulated separate sums for each tax group are returned to the PC. 
If a discount or surcharge is entered, it is printed out on a separate line and the accumulated sums over the different tax groups 
are respectively corrected.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_52_0_0.html">CMD_52_0_0</a></li></td>
					<td><pre>34H (52)	REGISTRATION AND DISPLAY

	Data field:
		TaxCd
		Price
	Response:	
		None

	Tab	One byte containing 09h
	TaxCd	One byte containing letter that indicates the tax group ('A', 'B', 'C', 'D', 'E', 'F'). There is a restriction, which 
		depends on disabled taxes (command 83).
	Price	This is the price - up to 8 valid digits.

	The fiscal printer will:
	-	Print out the text describing the sale together with the price and the code of the tax group.
	-	The price of the item sold is added to the accumulated sums in the registries of operational memory. In case of 
		overflow, the respective bits of status bytes are set.
	-	If there is a surcharge or discount made on the sum, it is printed out on a separate line and is added to 
		registries, specially reserved in the printer. The daily accumulated sums are printed out together with the daily 
		financial report.
	
	
	The command will not be executed successfully if:
	-	No fiscal memory has been opened
	-	The maximum possible number of sales have already been performed
	-	The command 53 (34H) has been successfully executed
	-	The sum under some of the tax groups has become negative
	-	The sum of the surcharge or discount within the receipt remains negative
	-	The journal is full

The price of the item is shown on the upper line of display and its description - on the lower.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_52_0_1.html">CMD_52_0_1</a></li></td>
					<td><pre>34H (52)	REGISTRATION AND DISPLAY

	Data field:	
		Line
		TaxCd
		Price
		Quan
		UN
		Perc
	Response:	
		None


	Line	A 20 byte string containing text, which describes the sale.
	TaxCd	One byte containing letter that indicates the tax group ('A', 'B', 'C', 'D', 'E', 'F'). There is a restriction, which 
		depends on disabled taxes (command 83).
	Sign	One byte with a value of '-'.
	Price	This is the price - up to 8 valid digits
	Quan	This is a non-mandatory parameter setting the quantity of the items sold. By default its value is 1.000 and its 
		length - 8 valid digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	Perc	Parameter showing the value of surcharge and discount (depending on the sign) in percent over the current sale. 
		Possible values are between -99.00% to 99.00%. 

	The fiscal printer will:
	-	Print out the text describing the sale together with the price and the code of the tax group.
	-	The price of the item sold is added to the accumulated sums in the registries of operational memory. In case of 
		overflow, the respective bits of status bytes are set.
	-	If there is a surcharge or discount made on the sum, it is printed out on a separate line and is added to 
		registries, specially reserved in the printer. The daily accumulated sums are printed out together with the daily 
		financial report.
	
	
	The command will not be executed successfully if:
	-	No fiscal memory has been opened
	-	The maximum possible number of sales have already been performed
	-	The command 53 (34H) has been successfully executed
	-	The sum under some of the tax groups has become negative
	-	The sum of the surcharge or discount within the receipt remains negative
	-	The journal is full

The price of the item is shown on the upper line of display and its description - on the lower.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_52_0_2.html">CMD_52_0_2</a></li></td>
					<td><pre>34H (52)	REGISTRATION AND DISPLAY

	Data field:
		Line
		TaxCd
		Price
		Quan
		UN
		AbsSum
	Response:
		None

	Line	A 20 byte string containing text, which describes the sale.
	TaxCd	One byte containing letter that indicates the tax group ('A', 'B', 'C', 'D', 'E', 'F'). There is a restriction, which 
		depends on disabled taxes (command 83).
	Sign	One byte with a value of '-'.
	Price	This is the price - up to 8 valid digits
	Quan	This is a non-mandatory parameter setting the quantity of the items sold. By default its value is 1.000 and its 
		length - 8 valid digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	AbsSum	Parameter which sets the value of discount or surcharge (depending on the sign) over the currently performed 
		sale.  Up to 8 significant digits. 

	The fiscal printer will:
	-	Print out the text describing the sale together with the price and the code of the tax group.
	-	The price of the item sold is added to the accumulated sums in the registries of operational memory. In case of 
		overflow, the respective bits of status bytes are set.
	-	If there is a surcharge or discount made on the sum, it is printed out on a separate line and is added to 
		registries, specially reserved in the printer. The daily accumulated sums are printed out together with the daily 
		financial report.
	
	
	The command will not be executed successfully if:
	-	No fiscal memory has been opened
	-	The maximum possible number of sales have already been performed
	-	The command 53 (34H) has been successfully executed
	-	The sum under some of the tax groups has become negative
	-	The sum of the surcharge or discount within the receipt remains negative
	-	The journal is full

The price of the item is shown on the upper line of display and its description - on the lower.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_53_0_0.html">CMD_53_0_0</a></li></td>
					<td><pre>35H (53)	CALCULATION OF A TOTAL

	Data field:
		PaidMode
		Sign
		Amount_In
	Resonse:	
		PaidCode
		Amount_Out

	PaidMode		A non-mandatory code indicating the terms of payment. It may have the following values:
			'P' 	Payment in cash
			'N' 	Payment via credit
			'C' 	Payment in cheques
			'D' 	Payment with a debit card
			'I'	Programmable payment 1
			'J'	Programmable payment 2
			'K'	Programmable payment 3
			'L'	Programmable payment 4

	Depending on the code, the sums are accumulated in different registers and may be recovered in the daily report.

	Sign		One byte with a value '+' indicating the Amount (the sum which has to be tendered)
	Amount_In	The sum tendered (up to 9 meaningful symbols)


	PaidCode		One byte - resulting from the execution of the command
			'F'	Error
			'E'	The calculated sub-total sum is negative. Payment is withheld and Amount will 
				contain a negative sub-total.
			'D'	If the paid sum is less than the sum on the receipt. The residual sum due for payment 
				is returned to Amount
			'R'	When the paid sum is greater than the sum on the receipt. A message "CHANGE" will 
				be printed out and the change will be returned to Amount.
			'I'	An error has occurred because the sum under one of the tax groups is negative. The 
				current subtotal is returned to Amount.
	Amount_Out	Up to 9 digits with a sign. Depends on PaidCode.

	This command starts the calculation of the sums from fiscal receipt, the printing of the sum with a special font and 
	showing the result on display. An additional text may also be printed. When the command has been successfully 
	executed a further command for opening a cash drawer is activated. If there is no input data, the printer will automatically 
	pay out the whole available sum in cash.

	The command will not be successful if:
	-	No fiscal receipt has been opened,
	-	The accumulated sum is negative,
	-	If some of the accumulated sums under taxation (tax group) is negative.
	
	After the successful completion of the command, fiscal printer will not perform the commands 49 and 51 within the 
	opened receipt, although it can still perform command 53.

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_53_0_1.html">CMD_53_0_1</a></li></td>
					<td><pre>35H (53)	CALCULATION OF A TOTAL

	Data field:	
		None
	Resonse:	
		PaidCode
		Amount_Out

	

	PaidCode		One byte - resulting from the execution of the command
			'F'	Error
			'E'	The calculated sub-total sum is negative. Payment is withheld and Amount will contain a 
				negative sub-total.
			'D'	If the paid sum is less than the sum on the receipt. The residual sum due for payment is 
				returned to Amount
			'R'	When the paid sum is greater than the sum on the receipt. A message "CHANGE" will be 
				printed out and the change will be returned to Amount.
			'I'	An error has occurred because the sum under one of the tax groups is negative. The current 
				subtotal is returned to Amount.
		Amount_Out	Up to 9 digits with a sign. Depends on PaidCode.

	This command starts the calculation of the sums from fiscal receipt, the printing of the sum with a special font and showing 
	the result on display. An additional text may also be printed. When the command has been successfully executed a further 
	command for opening a cash drawer is activated. If there is no input data, the printer will automatically pay out the whole 
	available sum in cash.

	The command will not be successful if:
	-	No fiscal receipt has been opened,
	-	The accumulated sum is negative,
	-	If some of the accumulated sums under taxation (tax group) is negative.
	
	After the successful completion of the command, fiscal printer will not perform the commands 49 and 51 within the opened 
	receipt, although it can still perform command 53.

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_53_0_2.html">CMD_53_0_2</a></li></td>
					<td><pre>35H (53)	CALCULATION OF A TOTAL

	Data field:	
		PaidMode
	Resonse:	
		PaidCode
		Amount_Out

	PaidMode		A non-mandatory code indicating the terms of payment. It may have the following values:
			'P' 	Payment in cash
			'N' 	Payment via credit
			'C' 	Payment in cheques
			'D' 	Payment with a debit card
			'I'	Programmable payment 1
			'J'	Programmable payment 2
			'K'	Programmable payment 3
			'L'	Programmable payment 4

	Depending on the code, the sums are accumulated in different registers and may be recovered in the daily report.


	PaidCode		One byte - resulting from the execution of the command
			'F'	Error
			'E'	The calculated sub-total sum is negative. Payment is withheld and Amount will contain 
				a negative sub-total.
			'D'	If the paid sum is less than the sum on the receipt. The residual sum due for payment is 
				returned to Amount
			'R'	When the paid sum is greater than the sum on the receipt. A message "CHANGE" will 
				be printed out and the change will be returned to Amount.
			'I'	An error has occurred because the sum under one of the tax groups is negative. The 
				current subtotal is returned to Amount.
	Amount_Out	Up to 9 digits with a sign. Depends on PaidCode.


	This command starts the calculation of the sums from fiscal receipt, the printing of the sum with a special font and showing 
	the result on display. 	An additional text may also be printed.
	When the command has been successfully executed a further command for opening a cash drawer is activated. If there is no 
	input data, the printer will automatically pay out the whole available sum in cash.

	The command will not be successful if:
	-	No fiscal receipt has been opened,
	-	The accumulated sum is negative,
	-	If some of the accumulated sums under taxation (tax group) is negative.
	
	After the successful completion of the command, fiscal printer will not perform the commands 49 and 51 within the opened 
	receipt, although it can still perform command 53.

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_53_0_3.html">CMD_53_0_3</a></li></td>
					<td><pre>35H (53)	CALCULATION OF A TOTAL

	Data field:
		Amount_In
	Resonse:	
		PaidCode
		Amount_Out

	Amount_In	The sum tendered (up to 9 meaningful symbols)


	PaidCode	One byte - resulting from the execution of the command
		'F'	Error
		'E'	The calculated sub-total sum is negative. Payment is withheld and Amount will contain a 
			negative sub-total.
		'D'	If the paid sum is less than the sum on the receipt. The residual sum due for payment is returned 
			to Amount
		'R'	When the paid sum is greater than the sum on the receipt. A message "CHANGE" will be printed 
			out and the change will be returned to Amount.
		'I'	An error has occurred because the sum under one of the tax groups is negative. The current subtotal 
			is returned to Amount.
	Amount_Out	Up to 9 digits with a sign. Depends on PaidCode.

	This command starts the calculation of the sums from fiscal receipt, the printing of the sum with a special font and showing 
	the result on display. An additional text may also be printed.
	When the command has been successfully executed a further command for opening a cash drawer is activated. If there is no 
	input data, the printer will automatically pay out the whole available sum in cash.

	The command will not be successful if:
	-	No fiscal receipt has been opened,
	-	The accumulated sum is negative,
	-	If some of the accumulated sums under taxation (tax group) is negative.
	
	After the successful completion of the command, fiscal printer will not perform the commands 49 and 51 within the opened 
	receipt, although it can still perform command 53.

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_54_0_0.html">CMD_54_0_0</a></li></td>
					<td><pre>36H (54)	PRINTING A FREE FISCAL TEXT

	Data field:	
		Input_Text
	Response:	
		None

	Input_Text	Up to 42 bytes text

	A fiscal receipt must be opened because, in the opposite case, the text will not be printed and the S1.1. 
	flag is raised. If the text is longer than 42 symbols, the redundant letters are cut off. 
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_56_0_0.html">CMD_56_0_0</a></li></td>
					<td><pre>38H (56)	CLOSING A FISCAL RECEIPT

	Data field:	
		No data
	Response:	
		RecCnt
		GlobRecCnt

	RecCnt		Fiscal or refund receipt count since last Z-report (4 bytes).
	GlobRecCnt	Global fiscal or refund receipt count (after the fiscalisation) (8 bytes).

	The accumulated sums from the fiscal receipt are added to the daily sums in the registries of operational 
	memory.

	The command will not be successful if:
	-	No fiscal receipt has been opened,
	-	Command 53 (35h) has failed,
	-	The sum paid under command 53 is less than the total sum on the fiscal receipt.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_58_0_0.html">CMD_58_0_0</a></li></td>
					<td><pre>3AH (58)	REGISTERING THE SALE OF AN ITEM

	Data field:	
		PLU
		Quan
		UN
		Perc
	Response:		
		None

	PLU	The individual number of the item - a whole number between 1 and 999999999 (not more than 9 digits).
	Quan	Parameter setting the quantity of the items for sale with a default value of 1.000. Length cannot be longer 
		than 8 meaningful digits (not more than 3 after the decimal point). The resulting singular price (*Quan) is 
		rounded up to the set number of digits 
		after the decimal point and also cannot be greater than 8 meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	Perc	Parameter showing the value of surcharge or discount (depending on the symbol) in percent over the 
		current sale. Possible values are between -99.00% to 99.00%. Up to 2 digits after the decimal point are 
		acceptable.


	The fiscal printer performs the following operations:
	-	The name, price and tax group of the item is read from items list, programmed in the printer.
	-	Prints out the name of the item, selected quantity and singular price. The second printed line contains 
		the final price together with the letter, designating the tax group from which the sale will be performed. 
		The registries for accumulated sums and item quantities are updated. 
	-	The price of the item is added to the accumulated sums in the registries of operational memory. In case 
		of overflow, the respective bytes from the status field will be set.
	-	If there is a discount or surcharge, it is printed out on a separate line and is added in specially selected 
		registries in the printer. The values from the whole day will be printed together with the daily financial 
		report.
	The command will not be successful if:
	-	No item has been programmed under the given number,
	-	No fiscal receipt has been opened,
	-	The maximum number of sales for one receipt (512) has already been registered.
	-	The command 35h has been successfully executed,
	-	The sum under one or more of the tax groups has turned out negative,
	-	The sum of surcharges and discounts within the receipt has remained negative,
	-	The journal is full</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_58_0_1.html">CMD_58_0_1</a></li></td>
					<td><pre>3AH (58)	REGISTERING THE SALE OF AN ITEM

	Data field:	
		PLU
		Quan
		UN
		AbsSum
	Response:	
		None

	PLU	The individual number of the item - a whole number between 1 and 999999999 (not more than 9 digits).
	Quan	Parameter setting the quantity of the items for sale with a default value of 1.000. Length cannot be longer 
		than 8 meaningful digits (not more than 3 after the decimal point). The resulting singular price (*Quan) is 
		rounded up to the set number of digits after the decimal point and also cannot be greater than 8 
		meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	AbsSum	Parameter which sets the value of discount or surcharge (depending on the sign) over the current sale. 
		Up to 8 significant digits. 




	The fiscal printer performs the following operations:
	-	The name, price and tax group of the item is read from items list, programmed in the printer.
	-	Prints out the name of the item, selected quantity and singular price. The second printed line contains 
		the final price together with the letter, designating the tax group from which the sale will be performed. 
		The registries for accumulated sums and item quantities are updated. 
	-	The price of the item is added to the accumulated sums in the registries of operational memory. In case 
		of overflow, the respective bytes from the status field will be set.
	-	If there is a discount or surcharge, it is printed out on a separate line and is added in specially selected 
		registries in the printer. The values from the whole day will be printed together with the daily financial 
		report.
	The command will not be successful if:
	-	No item has been programmed under the given number,
	-	No fiscal receipt has been opened,
	-	The maximum number of sales for one receipt (512) has already been registered.
	-	The command 35h has been successfully executed,
	-	The sum under one or more of the tax groups has turned out negative,
	-	The sum of surcharges and discounts within the receipt has remained negative,
	-	The journal is full</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_58_0_2.html">CMD_58_0_2</a></li></td>
					<td><pre>3AH (58)	REGISTERING THE SALE OF AN ITEM

	Data field:	
		PLU
		Quan
		UN
	Response:	
		None

	PLU	The individual number of the item - a whole number between 1 and 999999999 (not more than 9 digits).
	Quan	Parameter setting the quantity of the items for sale with a default value of 1.000. Length cannot be longer 
		than 8 meaningful digits (not more than 3 after the decimal point). The resulting singular price (*Quan) is 
		rounded up to the set number of digits after the decimal point and also cannot be greater than 8 
		meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".



	The fiscal printer performs the following operations:
	-	The name, price and tax group of the item is read from items list, programmed in the printer.
	-	Prints out the name of the item, selected quantity and singular price. The second printed line contains 
		the final price together with the letter, designating the tax group from which the sale will be performed. 
		The registries for accumulated sums and item quantities are updated. 
	-	The price of the item is added to the accumulated sums in the registries of operational memory. In case 
		of overflow, the respective bytes from the status field will be set.
	-	If there is a discount or surcharge, it is printed out on a separate line and is added in specially selected 
		registries in the printer. The values from the whole day will be printed together with the daily financial 
		report.
	The command will not be successful if:
	-	No item has been programmed under the given number,
	-	No fiscal receipt has been opened,
	-	The maximum number of sales for one receipt (512) has already been registered.
	-	The command 35h has been successfully executed,
	-	The sum under one or more of the tax groups has turned out negative,
	-	The sum of surcharges and discounts within the receipt has remained negative,
	-	The journal is full</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_58_0_3.html">CMD_58_0_3</a></li></td>
					<td><pre>3AH (58)	REGISTERING THE SALE OF AN ITEM

	Data field:	
		PLU
		Quan
	Response:	
		None

	PLU	The individual number of the item - a whole number between 1 and 999999999 (not more than 9 digits).
	Quan	Parameter setting the quantity of the items for sale with a default value of 1.000. Length cannot be longer 
		than 8 meaningful digits (not more than 3 after the decimal point). The resulting singular price (*Quan) is 
		rounded up to the set number of digits after the decimal point and also cannot be greater than 8 
		meaningful digits.


	The fiscal printer performs the following operations:
	-	The name, price and tax group of the item is read from items list, programmed in the printer.
	-	Prints out the name of the item, selected quantity and singular price. The second printed line contains 
		the final price together with the letter, designating the tax group from which the sale will be performed. 
		The registries for accumulated sums and item quantities are updated. 
	-	The price of the item is added to the accumulated sums in the registries of operational memory. In case 
		of overflow, the respective bytes from the status field will be set.
	-	If there is a discount or surcharge, it is printed out on a separate line and is added in specially selected 
		registries in the printer. The values from the whole day will be printed together with the daily financial 
		report.
	The command will not be successful if:
	-	No item has been programmed under the given number,
	-	No fiscal receipt has been opened,
	-	The maximum number of sales for one receipt (512) has already been registered.
	-	The command 35h has been successfully executed,
	-	The sum under one or more of the tax groups has turned out negative,
	-	The sum of surcharges and discounts within the receipt has remained negative,
	-	The journal is full</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_58_0_4.html">CMD_58_0_4</a></li></td>
					<td><pre>3AH (58)	REGISTERING THE SALE OF AN ITEM

	Data field:	
		PLU
		Quan
	Response:	
		None

	PLU	The individual number of the item - a whole number between 1 and 999999999 (not more than 9 digits).


	The fiscal printer performs the following operations:
	-	The name, price and tax group of the item is read from items list, programmed in the printer.
	-	Prints out the name of the item, selected quantity and singular price. The second printed line contains 
		the final price together with the letter, designating the tax group from which the sale will be performed. 
		The registries for accumulated sums and item quantities are updated. 
	-	The price of the item is added to the accumulated sums in the registries of operational memory. In case 
		of overflow, the respective bytes from the status field will be set.
	-	If there is a discount or surcharge, it is printed out on a separate line and is added in specially selected 
		registries in the printer. The values from the whole day will be printed together with the daily financial 
		report.
	The command will not be successful if:
	-	No item has been programmed under the given number,
	-	No fiscal receipt has been opened,
	-	The maximum number of sales for one receipt (512) has already been registered.
	-	The command 35h has been successfully executed,
	-	The sum under one or more of the tax groups has turned out negative,
	-	The sum of surcharges and discounts within the receipt has remained negative,
	-	The journal is full</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_60_0_0.html">CMD_60_0_0</a></li></td>
					<td><pre>3CH (60)	CANCEL FISCAL RECEIPT
	
	Data field:	
		None
	Response:	
		None

	The command cancels an open fiscal receipt. All sales in the receipt are discarded. 
	The message "** CANCELLED **" is printed and then the receipt is closed as non-fiscal. 
	The command is not permitted, if command 53 (Total) is already executed for this receipt.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_84_0_0.html">CMD_84_0_0</a></li></td>
					<td><pre>54h (84)	PRINTING A BAR CODE
	
	Data field:	
		BC_Type
		Data
	Response:	
		None

	BC_Type	Bar code type. 1 byte with possible value:
		'1'	EAN8 bar code. Data contains only digits and is 7 bytes long. The check sum is 
			automatically calculated and printed.
		'2'	EAN13 bar code. Data contains only digits and is 12 bytes long. The check sum 
			is automatically calculated and printed.
		'3'	Code128 bar code. Data contains symbols with ASCII codes between 32 and 127. 
			Data length is between 16 and 32 symbols 
			(depends on the content - the maximum length is if all symbol are digits). The 
			check sum is automatically calculated and printed.
		'4'	Interleaved 2 of 5 bar code. Data contains only digits and is up to 28 bytes long. 
			No check 	sum is calculated and printed.
		'5'	Interleaved 2 of 5 bar code. Data contains only digits and is up to 27 bytes long. 
			The check sum is automatically calculated and printed.

	The command prints a bar code. 
	Printing a bar code is permitted only in an opened fiscal or non-fiscal receipt. The bar code is centered. 
	If data length or content is not valid, nothing is printed and "Syntax error" status bit is set.
	Below the bar code human readable text of the bar code data is printed.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_84_0_1.html">CMD_84_0_1</a></li></td>
					<td><pre>54h (84)	PRINTING A BAR CODE
	
	Data field:
		BC_Type
		Data
	Response:	
		None

	BC_Type	Bar code type. 1 byte with possible value:
		'1'	EAN8 bar code. Data contains only digits and is 7 bytes long. The check sum is 
			automatically calculated and printed.
		'2'	EAN13 bar code. Data contains only digits and is 12 bytes long. The check sum is 
			automatically calculated and printed.
		'3'	Code128 bar code. Data contains symbols with ASCII codes between 32 and 127. 
			Data length is between 16 and 32 symbols 
			(depends on the content - the maximum length is if all symbol are digits). The 
			check sum is automatically calculated and printed.
		'4'	Interleaved 2 of 5 bar code. Data contains only digits and is up to 28 bytes long.
			No check	sum is calculated and printed.
		'5'	Interleaved 2 of 5 bar code. Data contains only digits and is up to 27 bytes long. 
			The check sum is automatically calculated and printed.

	The command prints a bar code. 
	Printing a bar code is permitted only in an opened fiscal or non-fiscal receipt. The bar code is centered. 
	If data length or content is not valid, nothing is printed and "Syntax error" status bit is set.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_109_0.html">CMD_109_0</a></li></td>
					<td><pre>Dh (109)	PRINTING A DUPLICATE RECEIPT

	Data field:	
		Count
	Response:	
		None

	Count	Number of duplicate receipts (only a value of 1 is accepted).


The command initiates the printing of a copy of the last closed receipt containing registered sales. 
The copy is marked as an "** NON-FISCAL **". Immediately after tax registration number, the 
inscription "DUPLICATE" is printed out in bold letters.
The printer will refuse to print a second copy of a receipt.
</pre></td>
				</tr>
			</table>
			</div>
		</td>
	</tr>
	<tr>
	  <td id="param">
			<label><span>!</span>DAILY CLOSURE</label>
			<div style="display: normal;">
			<table width="100%" border="1">
				<tr>
					<th width="300">Method name</th>
					<th>Short description</th>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_69_0_0.html">CMD_69_0_0</a></li></td>
					<td><pre>45h (69)	DAILY FINANCIAL REPORT

	Data field:
		Option
		N
		A
	Response:
		Closure
		TotA
		TotB
		TotC
		TotD
		TotE
		TotF

	Option	A non-mandatory parameter controlling the type of generated report.
		'0'	A Z-report is printed. The printout ends with inscriptions "** NON-FISCAL **" if the 
			printer is not fiscalised.
		'2'	A X-report is generated, i.e., no entry into the fiscal memory is made and no closures are 
			performed. 
		The printout ends with inscription "** NON-FISCAL **". The same actions may be generated directly 
		from the printer using the menu.
	N	The presence of this symbol at the end of the data cancels the option to clear the data accumulated on 
		the operators during a Z-report.
	A	The presence of this symbol at the end of the data cancels the option to clear the data about sold article 
		quantities during a Z-report.
	
	Closure	Fiscal closure (Daily report) number - 4 bytes.
	TotX	The totals under all tax categories - A, B, C, D, E and F - 12 bytes with a sign.

	If the command is with Option '0', it will try to send report to FTP Server. It tries 15 minutes, if it is not able to 
	send, it will be printed, and the device will be functionally, but when next Z report must be printed, it will try to 
	send the last one, and it will not print the new one, while last was not sent.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_0.html">CMD_120_0</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Electronic journal information.

	Data field: None
	Response:	
		JNum
		LastZNumber
		FirstZNumber
		LWLN
		FreeLines
		TotLines


	JNum		Journal number
	LastZNumber	Last Z-report number of current EJ Card.
	FirstZNumber	First Z-report number of current EJ Card.
	LWLN		Last written line number.
	FreeLines		Free lines count in EJ Card.
	TotLines		Total lines count in EJ Card</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_1.html">CMD_120_1</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 

	Data field:	None
	Response: 
		FP_ANSWER
		ANSWER_TEXT

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_2.html">CMD_120_2</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 
Full journal report (info and lines) for receipt in current period.

	Data field:	
		TRGT_YEAR
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	TRGT_YEAR	DATE TIME in format YY

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_3.html">CMD_120_3</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 
Full journal report (info and lines) for receipt in current period.

	Data field:	
		ZReceipt1
		ZReceipt2
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceipt1		DATE TIME in format YYMMDDhhmm
	ZReceipt2		DATE TIME in format YYMMDDhhmm

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_4.html">CMD_120_4</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 
The period will be from ZReceiptNumber1 and RReceiptNumber2 to ZReceiptNumber3 
and RReceiptNumber4 (with all receipts (R and X) in it).

	Data field:	
		ZReceiptNumber1
		RReceiptNumber2
		ZReceiptNumber3
		RReceiptNumber4
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceiptNumber1		Starting ZReceipt Number
	RReceiptNumber2		Starting RReceipt Number
	ZReceiptNumber3		Ending ZReceipt Number
	RReceiptNumber4		Ending RReceipt Number

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_5.html">CMD_120_5</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 
Only lines for every receipt in current period.

	Data field:
		TRGT_YEAR
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	TRGT_YEAR	DATE TIME in format YY

	FP_ANSWER
			'F'	No journal line found
			'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_6.html">CMD_120_6</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 
Only lines for every receipt in current period.

	Data field:	
		ZReceipt1
		ZReceipt2
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceipt1		DATE TIME in format YYMMDDhhmm
	ZReceipt2		DATE TIME in format YYMMDDhhmm

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_7.html">CMD_120_7</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 
The period will be from ZReceiptNumber1 and RReceiptNumber2 to 
ZReceiptNumber3 and RReceiptNumber4 (with all receipts (R and X) in it).

	Data field:
		ZReceiptNumber1
		RReceiptNumber2
		ZReceiptNumber3
		RReceiptNumber4
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceiptNumber1		Starting ZReceipt Number
	RReceiptNumber2		Starting RReceipt Number
	ZReceiptNumber3		Ending ZReceipt Number
	RReceiptNumber4		Ending RReceipt Number

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_8.html">CMD_120_8</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 
Only info for every receipt in current period.

	Data field:
		TRGT_YEAR
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	TRGT_YEAR	DATE TIME in format YY

	FP_ANSWER
			'F'	No journal line found
			'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_9.html">CMD_120_9</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 
Only info for every receipt in current period.

	Data field:
		ZReceipt1
		ZReceipt2
	Response:
		FP_ANSWER
		ANSWER_TEXT


	ZReceipt1		DATE TIME in format YYMMDDhhmm
	ZReceipt2		DATE TIME in format YYMMDDhhmm

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_10.html">CMD_120_10</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 
The period will be from ZReceiptNumber1 and RReceiptNumber2 to ZReceiptNumber3 
and RReceiptNumber4 (with all receipts (R and X) in it).
Only info for every receipt in current period.

	Data field:	
		ZReceiptNumber1
		RReceiptNumber2
		ZReceiptNumber3
		RReceiptNumber4
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceiptNumber1		Starting ZReceipt Number
	RReceiptNumber2		Starting RReceipt Number
	ZReceiptNumber3		Ending ZReceipt Number
	RReceiptNumber4		Ending RReceipt Number

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_11.html">CMD_120_11</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Device print electronic journal starting from the last ZReport, than all journal lines in 
current Z day using normal font size.
Period will be printed, not downloaded !!!
Full journal report (info and lines) for receipt in current period.

	Data field:	None
	Response: 
		FP_ANSWER
		ANSWER_TEXT

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_12.html">CMD_120_12</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
Full journal report (info and lines) for receipt in current period.
Device print electronic journal using normal font size.

	Data field:
		ZReceipt1
		ZReceipt2
	Response:
		FP_ANSWER
		ANSWER_TEXT


	ZReceipt1		DATE TIME in format YYMMDDhhmm
	ZReceipt2		DATE TIME in format YYMMDDhhmm

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_13.html">CMD_120_13</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
Full journal report (info and lines) for receipt in current period.
Device print electronic journal using normal font size.
The period will be from ZReceiptNumber1 and RReceiptNumber2 to 
ZReceiptNumber3 and RReceiptNumber4 (with all receipts (R and X) in it).

	Data field:	
		ZReceiptNumber1
		RReceiptNumber2
		ZReceiptNumber3
		RReceiptNumber4
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceiptNumber1		Starting ZReceipt Number
	RReceiptNumber2		Starting RReceipt Number
	ZReceiptNumber3		Ending ZReceipt Number
	RReceiptNumber4		Ending RReceipt Number

	FP_ANSWER
				'F'	No journal line found
				'P'	Journal line successfully read
	ANSWER_TEXT		The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_14.html">CMD_120_14</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
Only lines for every receipt in current period.
Device print electronic journal using normal font size.

	Data field:	
		ZReceipt1
		ZReceipt2
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceipt1		DATE TIME in format YYMMDDhhmm
	ZReceipt2		DATE TIME in format YYMMDDhhmm

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_15.html">CMD_120_15</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
The period will be from ZReceiptNumber1 and RReceiptNumber2 to 
ZReceiptNumber3 and RReceiptNumber4 (with all receipts (R and X) in it).

Only lines for every receipt in current period.
Device print electronic journal using normal font size.

	Data field:	
		ZReceiptNumber1
		RReceiptNumber2
		ZReceiptNumber3
		RReceiptNumber4
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceiptNumber1		Starting ZReceipt Number
	RReceiptNumber2		Starting RReceipt Number
	ZReceiptNumber3		Ending ZReceipt Number
	RReceiptNumber4		Ending RReceipt Number

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_16.html">CMD_120_16</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
The period will be from ZReceiptNumber1 and RReceiptNumber2 to 
ZReceiptNumber3 and RReceiptNumber4 (with all receipts (R and X) in it).

Only info for every receipt in current period.
Device print electronic journal using normal font size.

	Data field:
		ZReceipt1
		ZReceipt2
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceipt1		DATE TIME in format YYMMDDhhmm
	ZReceipt2		DATE TIME in format YYMMDDhhmm

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_17.html">CMD_120_17</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
The period will be from ZReceiptNumber1 and RReceiptNumber2 to 
ZReceiptNumber3 and RReceiptNumber4 (with all receipts (R and X) in it).

Only info for every receipt in current period.
Device print electronic journal using normal font size.

	Data field:	
		ZReceiptNumber1
		RReceiptNumber2
		ZReceiptNumber3
		RReceiptNumber4
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceiptNumber1		Starting ZReceipt Number
	RReceiptNumber2		Starting RReceipt Number
	ZReceiptNumber3		Ending ZReceipt Number
	RReceiptNumber4		Ending RReceipt Number

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_18.html">CMD_120_18</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Device print electronic journal starting from the last ZReport, than all journal lines in 
current Z day using normal font size.

Period will be printed, not downloaded !!!

Full journal report (info and lines) for receipt in current period.
Print journal using half-height font size.

	Data field:	None
	Response: 
		FP_ANSWER
		ANSWER_TEXT

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_19.html">CMD_120_19</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
Full journal report (info and lines) for receipt in current period.
Print journal using half-height font size.

	Data field:
		ZReceipt1
		ZReceipt2
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceipt1		DATE TIME in format YYMMDDhhmm
	ZReceipt2		DATE TIME in format YYMMDDhhmm

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_20.html">CMD_120_20</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
Full journal report (info and lines) for receipt in current period.
Print journal using half-height font size.
The period will be from ZReceiptNumber1 and RReceiptNumber2 to 
ZReceiptNumber3 and RReceiptNumber4 (with all receipts (R and X) in it).

	Data field:	
		ZReceiptNumber1
		RReceiptNumber2
		ZReceiptNumber3
		RReceiptNumber4
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceiptNumber1		Starting ZReceipt Number
	RReceiptNumber2		Starting RReceipt Number
	ZReceiptNumber3		Ending ZReceipt Number
	RReceiptNumber4		Ending RReceipt Number

	FP_ANSWER
				'F'	No journal line found
				'P'	Journal line successfully read
	ANSWER_TEXT		The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_21.html">CMD_120_21</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
Only lines for every receipt in current period.
Print journal using half-height font size.

	Data field:	
		ZReceipt1
		ZReceipt2
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceipt1		DATE TIME in format YYMMDDhhmm
	ZReceipt2		DATE TIME in format YYMMDDhhmm

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_22.html">CMD_120_22</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
The period will be from ZReceiptNumber1 and RReceiptNumber2 to 
ZReceiptNumber3 and RReceiptNumber4 (with all receipts (R and X) in it).

Only lines for every receipt in current period.
Print journal using half-height font size.

	Data field:	
		ZReceiptNumber1
		RReceiptNumber2
		ZReceiptNumber3
		RReceiptNumber4
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceiptNumber1		Starting ZReceipt Number
	RReceiptNumber2		Starting RReceipt Number
	ZReceiptNumber3		Ending ZReceipt Number
	RReceiptNumber4		Ending RReceipt Number

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_23.html">CMD_120_23</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
The period will be from ZReceiptNumber1 and RReceiptNumber2 to 
ZReceiptNumber3 and RReceiptNumber4 (with all receipts (R and X) in it).

Only info for every receipt in current period.
Print journal using half-height font size.

	Data field:	
		ZReceipt1
		ZReceipt2
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceipt1		DATE TIME in format YYMMDDhhmm
	ZReceipt2		DATE TIME in format YYMMDDhhmm

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_24.html">CMD_120_24</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
The period will be from ZReceiptNumber1 and RReceiptNumber2 to 
ZReceiptNumber3 and RReceiptNumber4 (with all receipts (R and X) in it).

Only info for every receipt in current period.
Print journal using half-height font size.

	Data field:	
		ZReceiptNumber1
		RReceiptNumber2
		ZReceiptNumber3
		RReceiptNumber4

	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceiptNumber1		Starting ZReceipt Number
	RReceiptNumber2		Starting RReceipt Number
	ZReceiptNumber3		Ending ZReceipt Number
	RReceiptNumber4		Ending RReceipt Number

	FP_ANSWER
				'F'	No journal line found
				'P'	Journal line successfully read
	ANSWER_TEXT		The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_25.html">CMD_120_25</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get next journal line.

	Data field:	
		None
	Response:	
		FP_ANSWER
		ANSWER_TEXT

	FP_ANSWER
			'F'	No journal line found
			'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_26.html">CMD_120_26</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Continue of command:
	120_11
	120_12
	120_13
	120_14
	120_15
	120_16
	120_17
	120_18
	120_19
	120_20
	120_21
	120_22
	120_23
	120_24
(starting with the first non-printed receipt) using normal font size.






	Data field:		None
	Response:		FP_ANSWER,ANSWER_TEXT

	FP_ANSWER
			'F'	No journal line found
			'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_27.html">CMD_120_27</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Continue of command:
	120_11
	120_12
	120_13
	120_14
	120_15
	120_16
	120_17
	120_18
	120_19
	120_20
	120_21
	120_22
	120_23
	120_24
(starting with the first non-printed receipt) using half-height font size.


	Data field:	
		None
	Response:	
		FP_ANSWER
		ANSWER_TEXT

	FP_ANSWER
			'F'	No journal line found
			'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
			</table>
			</div>
		</td>
	</tr>
	<tr>
	  <td id="param">
			<label><span>!</span>REPORTS</label>
			<div style="display: normal;">
			<table width="100%" border="1">
				<tr>
					<th width="300">Method name</th>
					<th>Short description</th>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_50_0_0.html">CMD_50_0_0</a></li></td>
					<td><pre>32h (50)	TAX RATES ENTERED DURING THE ACCOUNTED PERIOD

	Data field:
		StartDate
		EndDate
	Response:	
		Data

	StartDate		The starting date of the period - DDMMYY/6 bytes/
	EndDate		The end date of the period - DDMMYY /6 bytes/

	Data	
			'F' if no tax rates for the period have been found, or in case of error
			'PAA,BB,CC,DD,DDMMYY' if rates have been found, where 'P' means 'PASS' after which the last 
			active rates for the period are listed out as well as the date of their entry. If there are unused groups 
			(disabled by command 83) for them, instead of rate in percent a 'DT' is returned (Disabled tax).

			When Start and End are entered, the comma is mandatory.
			The command prints a report on the changes made in the decimal points and tax rates during the 
			selected period.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_73_0_0.html">CMD_73_0_0</a></li></td>
					<td><pre>49H (73)	DETAILED FISCAL MEMORY REPORT BY CLOSURE NUMBER

	Data field:	
		Ext
		StartRec
		EndRec
	Response:	
		None

	Ext	Optional parameter - the letter 'X'. If present, additional information is printed in the report: 
		Fiscalisation date and time, tax rate changes date and time, reset date and time. Additionally every 
		tax rates change divides the report in separate blocks with grand totals. 
		This is non-standard reports, but contains additional useful information.
	StartRec	The number of the starting fiscal entry - 4 bytes
	EndRec	The number of the ending fiscal entry - 4 bytes

	The command leads to printing of a detailed report of the fiscal memory from one selected number to another.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_79_0_0.html">CMD_79_0_0</a></li></td>
					<td><pre>4Fh (79)	SHORT FISCAL MEMORY REPORT BY CLOSURE DATE

	Data field:	 
		Ext 
		StartDate 
		EndDate 
	Response:	
		None

	Ext	Optional parameter - the letter 'X'. If present, additional information is printed in the 
		report: Fiscalisation date and time, tax rate changes 
		date and time, reset date and time. Additionally every tax rates change divides the report 
		in separate blocks with grand totals. 
		This is non-standard reports, but contains additional useful information.

	StartDate       Starting date - 6 bytes (DDMMYY)
	EndDate         End date - 6 bytes (DDMMYY)

	The command generates printing out of a short periodic financial report.
	If the second parameter is not present, then the command generates a short monthly or annual report. The syntax 
	in this case is:
	
	StartMonth - 4 bytes (MMYY) for monthly report.
	StartYear - 2 bytes (YY) for annual report.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_94_0_0.html">CMD_94_0_0</a></li></td>
					<td><pre>5Eh (94)	DETAILED FISCAL MEMORY REPORT BY CLOSURE DATE

	Data field:	
		Ext 
		StartDate
		EndDate
	Response:	
		None

	Ext	
		Optional parameter - the letter 'X'. If present, additional information is printed in the report: 
		Fiscalisation date and time, tax rate changes date and time, reset date and time. Additionally 
		every tax rates change divides the report in separate blocks with grand totals. 
		This is non-standard reports, but contains additional useful information.

	StartDate	
		Starting date of selected fiscal entry - 6 bytes (DDMMYY)

	EndDate	
		End date of the fiscal entry - 6 bytes (DDMMYY)

	This command prints out a detailed financial report of the period between two selected dates.
	If the second parameter is not present, then the command generates a short monthly or annual report. 
	The syntax in this case is:

	StartDate	
		Month - 4 bytes (MMYY) for monthly report.

	StartDate	
		Year - 2 bytes (YY) for annual report.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_95_0_0.html">CMD_95_0_0</a></li></td>
					<td><pre>5Fh (95)	SHORT FISCAL MEMORY REPORT BY CLOSURE NUMBER

	Data field:	
		Ext
		StartNumber
		EndNumber
	Response:	
		None

	Ext		
		Optional parameter - the letter 'X'. If present, additional information is printed in the report: 
		Fiscalisation date and time, tax rate changes date and time, reset date and time. Additionally 
		every tax rates change divides the report in separate blocks with grand totals. 
		This is non-standard reports, but contains additional useful information.

	StartNumber
		Starting number of fiscal entry

	EndNumber	
		End number of fiscal entry</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_105_0_0.html">CMD_105_0_0</a></li></td>
					<td><pre>68h (105)	OPERATOR'S REPORT

	Data field:	None
	Response:	None

Information on the sales, performed by the operators, is printed out where for each separate operator the 
following data is printed out: name, individual number, number of fiscal receipts, discharges made, surcharge, 
sum adjustments and accumulated total sums.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_111_0.html">CMD_111_0</a></li></td>
					<td><pre>6Fh (111)	ITEMS REPORT

	Data field:	
		Option
		Start
		End
	Reponse:	
		ErrorCode

	Option	
		Defines the type of information under print. Possible values:
		- 'S'	Only sold items are printed out. The data on these items include: 
			the individual number, VAT group, group, name, 
			single price, sold quantity and total sum for the day.
		- 'P'	All programmed items are printed out, containing their number, 
			VAT group, group, name, sold quantity, available quantity and 
			single price.

	START_PLU
		First article number (PLU) printed. PLUs less than this are not included in 
		the report. Default: 1.
	END_PLU
		Last article number (PLU) printed. PLUs greater than this are not included 
		in the report. Default: 999999999.

	ErrorCode
		One byte, showing the result from the operation and having the following 
		meaning:
			'P'	Successful command
			'F'	Unsuccessful command
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_111_1.html">CMD_111_1</a></li></td>
					<td><pre>6Fh (111)	ITEMS REPORT

	Data field:	
		Option
		Group
	Reponse:	
		ErrorCode

	Option	
		Defines the type of information under print. Possible values:
		- 'S'	Only sold items are printed out. The data on these items include: 
			the individual number, VAT group, group, name, single price, 
			sold quantity and total sum for the day.
		- 'P'	All programmed items are printed out, containing their number, 
			VAT group, group, name, sold quantity, available quantity and 
			single price.

	Group
		A number from 1 to 99. If present, only articles from this group 
		are printed, otherwise all articles are printed.

	ErrorCode
		One byte, showing the result from the operation and having the following 
		meaning:
			'P'	Successful command
			'F'	Unsuccessful command</pre></td>
				</tr>
			</table>
			</div>
		</td>
	</tr>
	<tr>
	  <td id="param">
			<label><span>!</span>INFORMATION TO HOST</label>
			<div style="display: normal;">
			<table width="100%" border="1">
				<tr>
					<th width="300">Method name</th>
					<th>Short description</th>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_62_0_0.html">CMD_62_0_0</a></li></td>
					<td><pre>3EH (62)	READING CURRENT DATE AND HOUR

	Data field:	
		None
	Response:	
		DD/MM/YY  HH:MM:SS
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_62_0_1.html">CMD_62_0_1</a></li></td>
					<td><pre>3EH (62)	READING CURRENT DATE AND HOUR

	Data field:	None
	Response:	
		DD	Day
		MM	Month
		YY	Year
		HH	Hour
		MM	Minute
		SS	Sec.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_64_0_0.html">CMD_64_0_0</a></li></td>
					<td><pre>40H (64)	LAST FISCAL CLOSURE DETAILS

	Data field:	
		Option
	Response:	
		Closure
		TotA
		TotB
		TotC
		TotD
		TotE
		TotF
		ClosureDate

	Option		'0'- TotX	Tax group total.
			'1'- TotX	Tax group VAT
	Closure		Closure (Z-report) number
	ClosureDate	Closure date in format DDMMYY.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_65_0_0.html">CMD_65_0_0</a></li></td>
					<td><pre>41H (65)	DAILY TOTALS

	Data field:
		Option
	Response:	
		TotA
		TotB
		TotC
		TotD
		TotE
		TotF

	Option	'0'- TotX	Tax group total.
		'1'- TotX	Tax group VAT
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_68_0_0.html">CMD_68_0_0</a></li></td>
					<td><pre>44h (68)	THE NUMBER OF FREE FIELDS IN THE FISCAL MEMORY

	Data field:	None
	Response:	
		Logical
		Physical

	Logical		The number of logical locations for fiscal entries (4 bytes)
	Physical		Not used. Repeats the previous entry.

	The number of free fields in the fiscal memory, reserved for saving information from the daily report.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_74_0_0.html">CMD_74_0_0</a></li></td>
					<td><pre>4Ah (74)	READING THE STATUS OPTIONS

	Data field:
		Option
	Response:	
		S0
		S1
		S2
		S3
		S4
		S5

	Option	One byte with the following meanings:
		'W'	All printer buffers must be printed out first.
		'X'	The status is returned immediately (default).
	Sn	Status byte n.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_74_0_1.html">CMD_74_0_1</a></li></td>
					<td><pre>4Ah (74)	READING THE STATUS OPTIONS

	Data field:	None
	Response:	
		S0
		S1
		S2
		S3
		S4
		S5

	Sn	Status byte n.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_76_0_0.html">CMD_76_0_0</a></li></td>
					<td><pre>4Ch (76)	STATUS OF THE FISCAL TRANSACTION

	Data field:	
		Option
	Repsonse:	
		FT_Opened
		Sales_Num
		Amount
		Tender

	Option		= 'T' If the parameter has been selected, the command will return the information on the 
			current state of the sum due for payment by client.

	FT_Opened	One byte, which is '1', if a fiscal or a non-fiscal receipt has been opened (which can be 
			understood from the status bytes) and '0' if there is no opened receipt.
	Sales_Num	The number of sales registered on the current or last fiscal receipt - 4 bytes.
	Amount		The sum from the last fiscal receipt - 9 bytes with a sign.
	Tender		The sum tendered against the current or the last receipt - 9 bytes with a sign (Only if Option 
			is present).
	
	The command supports the PC application's ability to monitor the status and, if needed, to restore and complete 
	an already started fiscal operation, which has been interrupted on emergency or out of time - for example, as a 
	result of a power failure.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_86_0_0.html">CMD_86_0_0</a></li></td>
					<td><pre>56H (86)	GET LATEST FISCAL MEMORY RECORD DATE

	Data field: 
		None
	Response:	 
		LFMR_DT

	LFMR_DT	
		Date and time of last (latest) record in the fiscal memory in format DD-MM-YYYY hh:mm:ss</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_86_0_1.html">CMD_86_0_1</a></li></td>
					<td><pre>56H (86)	GET LATEST FISCAL MEMORY RECORD DATE

	Data field: 
		None
	Response:	 
		DD
		MM
		YYYY
		HH
		MMM
		SS

	Date and time of last (latest) record in the fiscal memory:

	DD - Day
	MM - Month
	YYYY - Year
	HH - Hours
	MMM - Minutes
	SS - Sec.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_90_0_0.html">CMD_90_0_0</a></li></td>
					<td><pre>5Ah (90)	RETURNS DIAGONSTIC INFORMATION

	Data field:	
		None
	Response:	
		PrinterName
		FwRev_FwDate
		Chk
		ConfigSwitches
		SerialNumber

	PrinterName	
		Name of the printer (the string "FP2000").

	FwRev_FwDate	
		The version of the software program (4 bytes)+[Space(1 byte)]+The date of the firmware 
		program DDMmmYY(7 bytes).
	Chk	
		The EPROM control sum - a 4 bytes string in the hexadecimal code. 
		For example, if the control sum is 214Ah, it will be presented as 32h, 31h, 34h, 42h

	ConfigSwitches	
		The configuration switches from Sw1 to Sw8 - a 8 bytes string with '0' or '1'.

	Serial		
		The serial number - 10 bytes.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_97_0_0.html">CMD_97_0_0</a></li></td>
					<td><pre>61h (97)	READING THE SETTED TAX RATES

	Data field:	
		None
	Response:	
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF

	TaxA	Current tax rate A
	TaxB	Current tax rate B
	TaxC	Current tax rate C
	TaxD	Current tax rate D
	TaxE	Current tax rate E
	TaxF	Current tax rate F</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_99_0_0.html">CMD_99_0_0</a></li></td>
					<td><pre>63h (99)	Reading the TAX REGISTRATION NUMBER

	Data field:	
		None
	Response:	
		TIN
		VRN

	TIN	The TAX identification number as a text (9 bytes).
	VRN	The VAT identification number as a text (9 bytes).</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_103_0_0.html">CMD_103_0_0</a></li></td>
					<td><pre>67h (103)	INFORMATION ON THE CURRENT RECEIPT

	Data field:	
		None
	Response:	
		CanVd
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF

	CanVd	Possible/impossible return (sale registration with a negative sign) ['0' / '1']
	TaxA	The sum accumulated under tax A
	TaxB	The sum accumulated under tax B
	TaxC	The sum accumulated under tax C
	TaxD	The sum accumulated under tax D
	TaxE	The sum accumulated under tax E
	TaxF	The sum accumulated under tax F

The command offers information on sums accumulated so far under the different tax groups and whether it is 
possible to return the registered items sold.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_110_0.html">CMD_110_0</a></li></td>
					<td><pre>6Eh (110)	PAYMENT INFORMATION

	Data field:	
		None
	Response:	
		Cash
		Credit
		Debit
		Cheque
		Pay1
		Pay2
		Pay3
		Pay4
		Closure
		Receipt

	Cash	Paid in cash
	Credit	Payment credited
	Debit	Paid with a debit card
	Cheque	Paid with a cheque
	PayX	Payd with one of the additional payment types ('I', 'J', 'K', 'L').
	Closure	Current (last) fiscal entry
	Receipt	Number of the next fiscal receipt
	
Returns information on distribution of the daily sum according to terms of payment used.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_112_0.html">CMD_112_0</a></li></td>
					<td><pre>70h (112)	READING INFORMATION ON THE OPERATOR

Data field:	
	OperatorNumber
Response:		

	OperatorNumber	
			Number of the operator (1 to 16)

	ReceiptsNumber
			Number of fiscal receipts, issued by the operator

	RegisteredSalesNumber
			Number of registered sales

	TotalAccumulatedSum
			Total accumulated sum

	DiscountsNumber
			Number of discounts

	TotalDiscountsNumber
			Total number of discounts

	MarkUpNumber	
			Number of mark ups

	TotalMarkUpNumber
			Total number of mark ups made

	VoidNumber
			Number of voids (and corrections of sums)

	VoidsTotal
			Total sum of voids (and corrections of sums)

	OperatorName
			Name of the operator

	OperatorPassword			
			Operators password. Present only the printer is in service mode.

The command leads to the reading of the available information, which will be printed out in the 
operator's report. The sums are returned as floating-point numbers incorporating the currently 
set number of decimal places.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_113_0.html">CMD_113_0</a></li></td>
					<td><pre>71h (113)	READING THE NUMBER OF THE LAST PRINTED DOCUMENT

	Data field:	
		None
	Response:	
		Fiscal
		NonFiscal
		Document

	Fiscal	
		The number of the last issued fiscal receipt (8 digits)

	NonFiscal	
		The number of the last issued non-fiscal receipt (8 digits)

	Document	
		The number of the last issued document (8 digits)</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_0.html">CMD_114_0</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about active decimals and VAT rates for the Z-report record.

	Data field:	
		Closure1
	Response:	
		ErrorCode
		DecRec
		DecimalsCount
		VATEnabled
		PercA
		PercB
		PercC
		PercD
		PercE
		PercF
		DT

	Closure1	
		Number of the fiscal memory record.

	ErrorCode	
		One byte with a value of:
			- 'P'	The data are valid.
			- 'F'	Wrong control sum in the entry. No data available.
			- 'E'	The selected entry is empty. No data available.
	
	
	DecRec		Last (active) decimals and VAT rates record number.
	DecimalsCount	Decimals count for this Z-report record.
	VATEnabled	Enabled VAT rates mask - 4 bytes with values '0' or '1', where 
			'1' means "enabled".
	PercA		VAT rate for the corresponding VAT group in percents.
	PercB		VAT rate for the corresponding VAT group in percents.
	PercC		VAT rate for the corresponding VAT group in percents.
	PercD		VAT rate for the corresponding VAT group in percents.
	PercE		VAT rate for the corresponding VAT group in percents.
	PercF		VAT rate for the corresponding VAT group in percents.
	DT		Date and time of the data in format: DD-MM-YY hh:mm:ss.
	

The command returns information on different tax groups for each separate entry 
and or a selected period of time. 
Periodic references for longer time periods may take few seconds to process.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_1.html">CMD_114_1</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about total (turnover) sums for the Z-report record.

	Data field:	
		Closure1
	Response:		
		ErrorCode
		Clos
		Fisc
		TotA
		TotB
		TotC
		TotD
		TotE
		TotF

	Closure1		
		Number of the fiscal memory record.

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	Clos	Z-report record number.
	Fisc	Fiscal receipts count.
	TotA	Total (turnover) sum for the corresponding VAT group.
	TotB	Total (turnover) sum for the corresponding VAT group.
	TotC	Total (turnover) sum for the corresponding VAT group.
	TotD	Total (turnover) sum for the corresponding VAT group.
	TotE	Total (turnover) sum for the corresponding VAT group.
	TotF	Total (turnover) sum for the corresponding VAT group.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_2.html">CMD_114_2</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about total (turnover) sums for the Z-report record.

	Data field:	
		Closure1
		Closure2
	Response:	
		ErrorCode
		Clos
		Fisc
		TotA
		TotB
		TotC
		TotD
		TotE
		TotF

	Closure1		Number of the fiscal memory record.
	Closure2		The data returned is for the period with starting record 
			Closure1 and last record Closure2. 

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	Clos		Z-report record number.
	Fisc		Fiscal receipts count.
	TotA		Total (turnover) sum for the corresponding VAT group.
	TotB		Total (turnover) sum for the corresponding VAT group.
	TotC		Total (turnover) sum for the corresponding VAT group.
	TotD		Total (turnover) sum for the corresponding VAT group.
	TotE		Total (turnover) sum for the corresponding VAT group.
	TotF		Total (turnover) sum for the corresponding VAT group.

	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_3.html">CMD_114_3</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about net sums for the Z-report record.

	Data field:	
		Closure1
	Response:		
		ErrorCode
		Clos
		Fisc
		NetA
		NetB
		NetC
		NetD
		NetE
		NetF

	Closure1		Number of the fiscal memory record.

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	Clos		Z-report record number.
	Fisc		Fiscal receipts count.
	NetA		Net sum for the corresponding VAT group.
	NetB		Net sum for the corresponding VAT group.
	NetC		Net sum for the corresponding VAT group.
	NetD		Net sum for the corresponding VAT group.
	NetE		Net sum for the corresponding VAT group.
	NetF		Net sum for the corresponding VAT group.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_4.html">CMD_114_4</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about net sums for the Z-report record.

	Data field:	
		Closure1
		Closure2
	Response:	
		ErrorCode
		Clos
		Fisc
		NetA
		NetB
		NetC
		NetD
		NetE
		NetF

	Closure1		Number of the fiscal memory record.
	Closure2		The data returned is for the period with starting record 
			Closure1 and last record Closure2. 

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	Clos			Z-report record number.
	Fisc			Fiscal receipts count.
	NetA			Net sum for the corresponding VAT group.
	NetB			Net sum for the corresponding VAT group.
	NetC			Net sum for the corresponding VAT group.
	NetD			Net sum for the corresponding VAT group.
	NetE			Net sum for the corresponding VAT group.
	NetF			Net sum for the corresponding VAT group.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_5.html">CMD_114_5</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about VAT sums for the Z-report record.

	Data field:	
		Closure1
	Response:	
		ErrorCode
		Clos
		Fisc
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF

	Closure1		Number of the fiscal memory record.

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	Clos			Z-report record number.
	Fisc			Fiscal receipts count.
	TaxA			VAT sum for the corresponding VAT group.
	TaxB			VAT sum for the corresponding VAT group.
	TaxC			VAT sum for the corresponding VAT group.
	TaxD			VAT sum for the corresponding VAT group.
	TaxE			VAT sum for the corresponding VAT group.
	TaxF			VAT sum for the corresponding VAT group.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_6.html">CMD_114_6</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about VAT sums for the Z-report record.

	Data field:		
		Closure1
		Closure2
	Response:	
		ErrorCode
		Clos
		Fisc
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF

	Closure1		Number of the fiscal memory record.
	Closure2		The data returned is for the period with starting record 
			Closure1 and last record Closure2. 

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	Clos			Z-report record number.
	Fisc			Fiscal receipts count.
	TaxA			VAT sum for the corresponding VAT group.
	TaxB			VAT sum for the corresponding VAT group.
	TaxC			VAT sum for the corresponding VAT group.
	TaxD			VAT sum for the corresponding VAT group.
	TaxE			VAT sum for the corresponding VAT group.
	TaxF			VAT sum for the corresponding VAT group.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_7.html">CMD_114_7</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about VAT sums for the Z-report record.

	Data field:	
		Closure1
	Response:	
		ErrorCode
		Clos
		DecRec
		ResetRec
		HeaderRec
		TechIntervRec
		FMDisc
		PRNDisc

	Closure1		Number of the fiscal memory record.

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	Clos		Z-report record number.
	DecRec		Last (active) decimals and VAT rates record number.
	ResetRec		Last RAM reset number for this Z-report record.
	HeaderRec	Last Header Change number for this Z-report record.
	TechIntervRec	Last Technical Intervention number for this Z-report record.
	FMDisc		Last FM Disconnection number for this Z-report record.
	PRNDisc		Last PRN Disconnection number fot this Z-report record.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_8.html">CMD_114_8</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


Information about decimals and VAT rates record.

	Data field:	
		Closure1
	Response:		
		ErrorCode
		DecimalsCount
		VATEnabled
		PercA	
		PercB
		PercC
		PercD
		PercE
		PercF
		DT

	Closure1		Number of the fiscal memory record.

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	DecimalsCount	Decimals count for this Z-report record.
	VATEnabled	Enabled VAT rates mask - 4 bytes with values '0' or '1', where 
			'1' means "enabled".
	PercA		VAT rate for the corresponding VAT group in percents.
	PercB		VAT rate for the corresponding VAT group in percents.
	PercC		VAT rate for the corresponding VAT group in percents.
	PercD		VAT rate for the corresponding VAT group in percents.
	PercE		VAT rate for the corresponding VAT group in percents.
	PercF		VAT rate for the corresponding VAT group in percents.
	DT		Date and time of the data in format: DD-MM-YY hh:mm:ss.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_9.html">CMD_114_9</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about RAM reset record.

	Data field:	
		Closure1
	Response:		
		ErrorCode
		DT

	Closure1		Number of the fiscal memory record.

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	DT		Date and time of the data in format: DD-MM-YY hh:mm:ss.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_10.html">CMD_114_10</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about HEADER record.

	Data field:	
		Closure1
		Closure2
	Response:	
		ErrorCode
		DT
		HeaderLine

	Closure1		Number of the fiscal memory record.
	Closure2		This parameter selects the required header line (0 to 5).

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	DT		Date and time of the data in format: DD-MM-YY hh:mm:ss.
	HeaderLine	The HEADER line, which is defined.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_11.html">CMD_114_11</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about Technical Intervention record.

	Data field:	
		Closure1
	Response:	
		ErrorCode[,DT]

	Closure1
		Number of the fiscal memory record.

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	DT
		Date and time of the data in format: DD-MM-YY hh:mm:ss.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_116_0.html">CMD_116_0</a></li></td>
					<td><pre>74h (116)	READ FISCAL MEMORY BLOCK

	Data field:	
		TRGT_ADDR
		BlockLength
	Response:	
		AnswerData

	TRGT_ADDR	Starting address in the fiscal memory in hexadecimal 
			representation (up to 5 hexadecimal digits). 
			From 00000 to 3FFFF for 2 Mbit fiscal memory.
	BlockLength	Block length. From 1 to 64.
	AnswerData	The data, read from the fiscal memory in hexadecimal form 
			(2 symbols for each data byte).

This command offers the option to read directly a block of data from the fiscal memory. It 
is possible to read the whole fiscal memory, sending the command many times with different 
start addresses.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_118_0.html">CMD_118_0</a></li></td>
					<td><pre>76h (118)	GET SHIFT LENGTH

	Data field:	
		None
	Response:	
		Seconds

	Seconds	
		The time since the first issued fiscal or refund receipt after Z-report in 
		seconds.

This command is used to check if a Z-report is needed. After the returned value reaches 86400 
(24 hours), the printer will print a warning message at the end of each fiscal or refund receipt.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_121_0.html">CMD_121_0</a></li></td>
					<td><pre>79h (121)	READ CODE MEMORY BLOCK

	Data field:	
		TRGT_ADDR
		BlockLength
	Response:	
		AnswerData

	TRGT_ADDR	Starting address in the code memory in hexadecimal 
			representation (up to 5 hexadecimal digits). 
			From 00000 to 4FFFF.
	BlockLength	Block length. From 1 to 64.
	AnswerData	The data, read from the code memory in hexadecimal 
			form (2 symbols for each data byte).
			

The value (TRGT_ADDR+BlockLength) may not be greater than 30000h 
(for example Address=2FFF0 and Bytes=17 is wrong).

This command offers the option to read directly a block of data from the code memory 
(firmware). It is possible to read the whole code memory, sending the command many times 
with different start addresses.
</pre></td>
				</tr>
			</table>
			</div>
		</td>
	</tr>
	<tr>
	  <td id="param">
			<label><span>!</span>PRINTER CONTROL COMMANDS</label>
			<div style="display: normal;">
			<table width="100%" border="1">
				<tr>
					<th width="300">Method name</th>
					<th>Short description</th>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_44_0_0.html">CMD_44_0_0</a></li></td>
					<td><pre>2Ch (44)		ADVANCING PAPER

	Data field:		Lines
	Response:		None
	
	Lines		Advancing paper measured in text lines. The programmed line count cannot be greater 
			than 99 (1 or 2 bytes).</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_45_0_0.html">CMD_45_0_0</a></li></td>
					<td><pre>2Dh (45)	CUTTING OFF PRINTED DOCUMENT

	Data field:		None
	Response:		None

The command causes the cutting off of the printed, ready document. It must be considered that the program 
must advance the paper with at least two lines or the document will not be cut off correctly. If the printer is in 
"automatic cut off" mode, it positions the paper itself and the command becomes redundant.
When the printing mechanism blocks for some reason, open the cover, remove the paper from the cutter region 
and switch the printer off and on. The cutter will go to it's home position and if not damaged, will be ready to use. </pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_92_0_0.html">CMD_92_0_0</a></li></td>
					<td><pre>5Ch (92)	PRINT SEPARATOR LINE

Data field:
	LineType
Response:	
	None

	LineType	The type of the separator line. One byte with possible value:
		'1'	The line is filled with the symbol '-'.
		'2'	The line is filled with the symbols '-' and ' ' (space).
		'3'	The line is filled with the symbols '='.

The command prints a separator line using the full width of the paper (36 symbols). It is permitted in an open 
fiscal, non-fiscal or refund receipt only</pre></td>
				</tr>
			</table>
			</div>
		</td>
	</tr>
	<tr>
	  <td id="param">
			<label><span>!</span>DISPLAY</label>
			<div style="display: normal;">
			<table width="100%" border="1">
				<tr>
					<th width="300">Method name</th>
					<th>Short description</th>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_33_0_0.html">CMD_33_0_0</a></li></td>
					<td><pre>21h (33)	Clearing the display

	Data field:	None
	Response:	None

A clear display command is sent. If a fiscal receipt is opened and SW3 is 
OFF, only the lower line is cleared.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_35_0_0.html">CMD_35_0_0</a></li></td>
					<td><pre>23h (35)	Text on the lower line of display

	Data field:		TRGT_TEXT
	Response:		None

	TRGT_TEXT	A text of up to 20 symbols sent directly to display. 
			Prior to that, a command for positioning and clearing 
			the lower line is sent.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_47_0_0.html">CMD_47_0_0</a></li></td>
					<td><pre>2F (47)	DISPLAYING A TEXT ON THE UPPER LINE OF DISPLAY

	Data field:		Text
	Response:		None

	Text	A text of 20 symbols, which is sent directly to the display. Prior to that, a command for 
		positioning and clearing of the upper line. 
		If a fiscal receipt is opened and SW1 is OFF, the command is rejected.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_63_0_0.html">CMD_63_0_0</a></li></td>
					<td><pre>3FH (63)	DISPLAYING THE DATE AND HOUR

	Data field:	None
	Response:	None

	Current date and time are displayed on lower line using the format: DD-MM-YYYY:HHMMSS.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_100_0_0.html">CMD_100_0_0</a></li></td>
					<td><pre>64h (100)	SHOWING TEXT ON DISPLAY

	Data field:	
		INPUT_TEXT
	Response:	
		None

	INPUT_TEXT	
		A text of no more than 40 symbols sent for displaying. If symbols with ASCII codes 
		smaller than 20h (control symbols), they are increased with 40h and are preceded by 10h.
		Example: To send 1Bh, 4Bh, 00h the data field will have to contain 10h, 5Bh, 10h, 40h.</pre></td>
				</tr>
			</table>
			</div>
		</td>
	</tr>
	<tr>
	  <td id="param">
			<label><span>!</span>OTHER</label>
			<div style="display: normal;">
			<table width="100%" border="1">
				<tr>
					<th width="300">Method name</th>
					<th>Short description</th>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_36_0_0.html">CMD_36_0_0</a></li></td>
					<td><pre>24H (36)	SET LAN SETTINGS

Works only with service jumper!!!
Returns current settings.

	Data field:		None

	Response:		IPAddr
			SubnetMask
			TCPPort
			DefGateway
			MACAddr

	IPAddr		4 numbers up to 255 separated with dot, represented device IP address.
	SubnetMask	4 numbers up to 255 separated with dot, represented device Subnet mask.
	TCPPort		4 numbers up to 255 separated with dot, represented device IP port.
	DefGateway	4 numbers up to 255 separated with dot, represented device Default Gateway.
	MACAddr	Up to 12 hexadecimals symbols represented device MAC address. 

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_36_0_1.html">CMD_36_0_1</a></li></td>
					<td><pre>24H (36)	SET LAN SETTINGS

Works only with service jumper!!!


	Data field:		
		IPAddr
		SubnetMask
		TCPPort
		DefGateway
		MACAddr

	Response:	
		None

	IPAddr		4 numbers up to 255 separated with dot, represented device IP address.
	SubnetMask	4 numbers up to 255 separated with dot, represented device Subnet mask.
	TCPPort		4 numbers up to 255 separated with dot, represented device IP port.
	DefGateway	4 numbers up to 255 separated with dot, represented device Default Gateway.
	MACAddr	Up to 12 hexadecimals symbols represented device MAC address. 
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_43_0_0.html">CMD_43_0_0</a></li></td>
					<td><pre>2Bh (43)	SETTING FOOTER AND PRINTING OPTIONS
	
	Data field:
		Item
		Text
	Response:	
		Entries from the data field

FOOTER consists of 2 lines of text printed at the end of each receipt.
HEADER and FOOTER are automatically center aligned.

Item		One symbol having the following meaning
"0".."5"		Selects the THE HEADER (any one of numbers will record the whole Header).
"6" or "7"		Selects the first or second FOOTER (TAX OFFICE) line.
"B"		Set bar code height in pixels (0.125 mm). Possible values from 24 (3 mm) to 240 (30 mm). 
		The barcode is printed with command 84 (54H).
"C"		Permission/rejection of the automatic cutting of paper after each receipt. After switching ON, the 
		performance of printer is defined in accordance with the setting of the switch SW1.
"D"		Set print darkness. Possible values: 
'1':		Very low
'2':		Low
'3':		Normal
'4':		Dark
'5':		Very dark
"L"		Height of graphic logo and permission/rejection of the printing of graphic logo immediately before the header. 
		This logo is defined with command 115 (73H).
"X"		Enable / disable automatic cash drawer pulse in commands 53 (35H) and 70 (46H).
"I"		Gives us the option to read values, set earlier with command 43. After the letter "I" only one more symbol 
		follows which coincides with some of the above.

Text		A text string:

If <Item> is '0'..'5' - 
LineX		The HEADER line, which is defined. Up to 48 bytes, but the total data length must be no more than 218 symbols. 
		Only the needed line count must be set (If the name and address did not require 6 lines).
Tab		Tabulation (ASCII code 09h).

The whole text of HEADER which will be writed in Fiscal Memory at once!!! Before the fiscalisation the header is not written to the 
fiscal memory and may be changed unlimited times. Command 72 (Fiscalisation) writes the first names record with the currently 
programmed header lines. After the fiscalisation 9 changes are allowed.

If <Item> is '6' or '7' - the text of the first or second footer line (up to 48 symbols).
If <Item> = 'B' - A number - the height of bar code in pixels.
If <Item> = 'C' - One symbol value '0' or '1', where "0" forbids and "1" permits the automatic cutting of the receipt.
If <Item> = 'D' - The print darkness (1 to 5).
If <Item> = `L' Syntax <Enabled>,<Height>

Enabled	'0' or '1', where '1' means, that logo printing is enabled.
Height	Graphics logo height in lines (0.125 mm). A number from 8 to 96.
If <Item> = 'X' - One symbol: '0' or '1', where '1' disables and '0' enables automatic cash drawer pulse in commands 53 (35H) and 
70 (46H).

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_43_0_1.html">CMD_43_0_1</a></li></td>
					<td><pre>2Bh (43)	SETTING FOOTER AND PRINTING OPTIONS
	
	Data field:
		Item
		Text
	Response:	
		Entries from the data field

FOOTER consists of 2 lines of text printed at the end of each receipt.
HEADER and FOOTER are automatically center aligned.

Item		One symbol having the following meaning
"0".."5"		Selects the THE HEADER (any one of numbers will record the whole Header).
"6" or "7"		Selects the first or second FOOTER (TAX OFFICE) line.
"B"		Set bar code height in pixels (0.125 mm). Possible values from 24 (3 mm) to 240 (30 mm). The barcode is 
		printed with command 84 (54H).
"C"		Permission/rejection of the automatic cutting of paper after each receipt. After switching ON, the performance 
		of printer is defined in accordance with the setting of the switch SW1.
"D"		Set print darkness. Possible values: 
'1':		Very low
'2':		Low
'3':		Normal
'4':		Dark
'5':		Very dark
"L"		Height of graphic logo and permission/rejection of the printing of graphic logo immediately before the header. 
		This logo is defined with command 115 (73H).
"X"		Enable / disable automatic cash drawer pulse in commands 53 (35H) and 70 (46H).
"I"		Gives us the option to read values, set earlier with command 43. After the letter "I" only one more symbol follows 
		which coincides with some of the above.

Text		A text string:
If <Item> is '0'..'5' 
LineX		The HEADER line, which is defined. Up to 48 bytes, but the total data length must be no more than 218 symbols. 
		Only the needed line count must be set (If the name and address did not require 6 lines).
Tab		Tabulation (ASCII code 09h).

The whole text of HEADER which will be writed in Fiscal Memory at once!!! Before the fiscalisation the header is not written to the fiscal 
memory and may be changed unlimited times. Command 72 (Fiscalisation) writes the first names record with the currently programmed 
header lines. After the fiscalisation 9 changes are allowed.

If <Item> is '6' or '7' - the text of the first or second footer line (up to 48 symbols).
If <Item> = 'B' - A number - the height of bar code in pixels.
If <Item> = 'C' - One symbol value '0' or '1', where "0" forbids and "1" permits the automatic cutting of the receipt.
If <Item> = 'D' - The print darkness (1 to 5).
If <Item> = `L' Syntax <Enabled>,<Height>

Enabled	'0' or '1', where '1' means, that logo printing is enabled.
Height	Graphics logo height in lines (0.125 mm). A number from 8 to 96.
If <Item> = 'X' - One symbol: '0' or '1', where '1' disables and '0' enables automatic cash drawer pulse in commands 53 (35H) 
and 70 (46H).
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_48_0_1.html">CMD_48_0_1</a></li></td>
					<td><pre>30h (48)	OPENING A FISCAL CLIENT'S RECEIPT

	Data field:
		OpCode
		OpPwd
		TillNmb
		BuyerLine1
		BuyerLine2
		BuyerLine3
		TIN
		VRN
	Response:	
		RecCnt
		GlobRecCnt



	OpCode		Operator's number (1 to 16)
	OpPwd		Operator's password (4 to 8 digits)
	TillNmb		Number of point of sale (a whole number of maximum 5 digits)
	BuyerLineX	Buyer's 3 line info 
	TIN		Buyers tax identification number
	VRN		Buyers VAT identification number

	RecCnt		Fiscal receipt count since last Z-report (4 bytes).
	GlobRecCnt	Global fiscal receipt count (after the fiscalisation) (8 bytes).



The FP performs the following actions:
	Prints the HEADER
	Prints the tax registration number
	Prints the number and name of operator as well as the cashier desk number
	RecCnt and GlobRecCnt are returned 

The command will not be successful if:
	-	There is an opened fiscal or non-fiscal receipt;
	-	The maximum number of receipts, as fixed for the day, has already been issued;
	-	The fiscal memory is full;
	-	The fiscal memory is damaged;
	-	No code or operator password, or cashier desk number available;
	-	The HEADER is not programmed;
	-	No tax registration number available;
	-	Wrong operator password;
	-	The clock needs setting;
	-	Journal is full;
	-	After entering three wrong operator's passwords, the printer blocks and must be switched 
		off and on again to restart operation.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_70_0_0.html">CMD_70_0_0</a></li></td>
					<td><pre>46h (70)	INTERNAL DEBITING AND CREDITING (serve In and Out)

	Data field:	
		InputSum
	Response:	
		ExitCode
		CashSum
		ServIn
		ServOut

	InputSum		The sum, which will be registered (up to 9 bytes). Depending on the sign of the digit, this 
			sum is interpreted either as credit or debit (ServeIn or ServeOut).

	ExitCode		One byte:
			'P'	The order has been completed. If the ordered sum is not 0, the printer will print 
				an interior receipt for registering the operation.
			'F'	The order has been cancelled. This happens if:
				-	The cash sum available is less than the ordered interior credit (ServeIn),
				-	There is an opened fiscal and non-fiscal receipt.

	CashSum		Available cash. Apart from this command, the sum grows after each payment in cash.
	ServIn		The sum from all commands "Interior credit"
	ServOut		The sum from all commands "Interior debit"

	Changes the content of the cash availability register. Depending on the sign of the sum in question, it is 
	accumulated in the register for interior debit-credit. The information is not saved in the fiscal memory of device 
	and is accessible until the performance of the daily closure. It is printed out at the command 69 (45h) and at the 
	generation of the daily report without closure from the printer itself. At successful completion of this 
	command, the drawer "kick-out" function is automatically activated.


</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_71_0_0.html">CMD_71_0_0</a></li></td>
					<td><pre>47h (71)	PRINTING DIAGNOSTIC INFORMATION

	Data field:	None
	Response:	None

	The command initiates the generation of an interior receipt containing diagnostic information as follows:
		-	Prints the date and version of the employed software,
		-	Prints the control sum of the employed firmware,
		-	Prints the serial port's band rate,
		-	Prints out the status of configuration keys and number of the country, the status 
			options being:

			Sw8 - Selects serial speed
			Sw7 - Selects serial speed
			Sw6 - Selects serial speed
			Sw5 - Not used
			Sw4 - Automatic paper cutting
			Sw3 - Half Cut
			Sw2 - Obligatory display
			Sw1 - Transparent display

			************************************
			Sw8	Sw7	Sw6	Speed
			************************************
			0	0	0	1200 bps
			0	0	1	2400 bps
			0	1	0	4800 bps
			0	1	1	9600 bps
			1	0	0	19200 bps
			1	0	1	38400 bps
			1	1	0	57600 bps
			1	1	1	115200 bps
			************************************

		-	Prints emergency time after power supply cut-off,
		-	Prints the number, date and hour of the last reset of the RAM (if there is such),
		-	Prints the current temperature of the two printer heads,
		-	Prints the overall number of fields in the fiscal memory and the number of the free fields,
		-	Prints the current date and hour.

	The command will not be executed when there is an open receipt in progress or when the paper roll has finished. 
	It may also be activated using the printer menu.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_80_0_0.html">CMD_80_0_0</a></li></td>
					<td><pre>50h (80)	SOUND SIGNAL

	Data field:	
		SoundData
	Response:	
		None

	This command is used for making (beeping) a sequence of sounds with a certain frequency and duration. 
	The data is in format, similar to the one used for writing notes and can be of any length up to 218 bytes. 
	The first invalid character cancels the command. If the input string is empty, the one sound signal with 
	frequency 2 kHz and duration 300 ms is emitted. 

	SoundData format is a sequence of the following sub-commands:

	-	Notes of the scale: One latine letter with value from 'A' to 'G'.
			'C' - Do
			'D' - Re
			'E' - Mi
			'F' - Fa
			'G' - Sol
			'A' - La
			'B' - Si
		If immediately after the note comes character '#', then the note is higher in pitch by a semitone (sharp). 
		If immediately after the note comes character '&', then the note is lower in pitch by a semitone (flat). 

	-	Pause: Character space (ASCII 20h).
		After a note or pause there can be one or a few bytes, which specify the duration. Valid are characters 
		from '0' to '5', they have the following meaning:
			'0'	basic duration of a note/pause
			'1'	basic duration * 2
			'2'	basic duration * 4
			'3'	basic duration * 8
			'4'	basic duration * 16
			'5'	basic duration * 32
		If there are a few durations one after another they are summed up. 

	-	Going to higher scale: character '+'.
	-	Going to lower scale: character '-'.
	-	Specifying tempo: character '^', followed by a number. The number specifies the percentage: duration 
		of notes and intervals to basic duration. 
		Values:
			'1'	200 %
			'2'	175 %
			'3'	140 %
			'4'	120 %
			'5'	100 %
			'6'	80 %
			'7'	60 %
			'8'	50 %
			'9'	40 %

	-	Return to scale 1 (it is default). Character '@'. Tone 'La' in it is 440 Hz.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_93_0_0.html">CMD_93_0_0</a></li></td>
					<td><pre>5Dh (93)	GET DISCOUNTS AND MARKUPS

	Data field:	
		None
	Response:	
		DiscountsCnt
		DiscountsSum
		MarkupsCnt
		MarkupsSum


	DiscountsCnt	
		Number of Discounts.

	DiscountsSum	
		Sum of Discounts.

	MarkupsCnt	
		Number of Markups.

	MarkupsSum	
		Sum of Markups.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_89_0_0.html">CMD_89_0_0</a></li></td>
					<td><pre>59h (89)	PROGRAMMING THE PRODUCTION TEST AREA

	Data field:	
		None
	Response:	
		Result
		Free

	Entry into the fiscal memory is done.

	FP_Result	
		'P'	No error
		'F'	Error

	FreeRecords
		The number of the free blocks left for saving such entries - 4 bytes.

The command is executed for testing the fiscal memory.
Test block for entries into the fiscal memory: 55h,AAh,33h,CCh,5Ah, A5h,3Ch,C3h
If - and when - the S1.1 flag has been raised, the fiscal memory has not been formatted or is in 
the READONLY mode.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_89_0_1.html">CMD_89_0_1</a></li></td>
					<td><pre>59h (89)	PROGRAMMING THE PRODUCTION TEST AREA

	Data field:	
		None
	Response:	
		Result
		Free

	There will be no 'save' performed and only the parameters will be returned.

	FP_Result	
		'P'	No error
		'F'	Error

	FreeRecords
		The number of the free blocks left for saving such entries - 4 bytes.

The command is executed for testing the fiscal memory.
Test block for entries into the fiscal memory: 55h,AAh,33h,CCh,5Ah, A5h,3Ch,C3h
If - and when - the S1.1 flag has been raised, the fiscal memory has not been formatted or is in 
the READONLY mode.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_106_0_0.html">CMD_106_0_0</a></li></td>
					<td><pre>6Ah (106)	DRAWER KICK OUT

	Data field:	
		mSec
	Response:	
		None

	mSec	The length of the impulse in milliseconds (5-100)
	
Sends an impulse for opening the cash drawer. This parameter sets a new value for the length of the impulse, which 
is stored in the memory of the printer. 
If this parameter is skipped, the last entered value remains valid. After memory RESET, a value of 15 ms is set.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_117_0.html">CMD_117_0</a></li></td>
					<td><pre>75h (117)	REGISTERINg TECHNICAL INTERVENTION

	Data field:	None
	Response:	None

The command is permitted only when the service jumper is placed on the main board of the 
printer. There is place for 150 technical intervention records in the fiscal memory.</pre></td>
				</tr>
			</table>
			</div>
		</td>
	</tr>
	<tr>
	  <td id="param">
			<label><span>!</span>SERVICE</label>
			<div style="display: normal;">
			<table width="100%" border="1">
				<tr>
					<th width="300">Method name</th>
					<th>Short description</th>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_127_0.html">CMD_127_0</a></li></td>
					<td><pre>7Fh (127)	RAM RESET

	Data field:	None
	Response:	None

The command clears the operational memory of the printer (like the CMOS error). 
After executing it, the clock must be set with command 61, which writes a "CMOS error" 
record in the fiscal memory with this date and time.
The command is permitted only when the service jumper is placed on the main board of 
the printer. There is place for 100 records in the fiscal memory.</pre></td>
				</tr>
			</table>
			</div>
		</td>
	</tr>
	<tr>
	  <td id="param">
			<label><span>!</span>All methods</label>
			<div style="display: normal;">
			<table width="100%" border="1">
				<tr>
					<th width="300">Method name</th>
					<th>Short description</th>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_33_0_0.html">CMD_33_0_0</a></li></td>
					<td><pre>21h (33)	Clearing the display

	Data field:	None
	Response:	None

A clear display command is sent. If a fiscal receipt is opened and SW3 is 
OFF, only the lower line is cleared.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_35_0_0.html">CMD_35_0_0</a></li></td>
					<td><pre>23h (35)	Text on the lower line of display

	Data field:		TRGT_TEXT
	Response:		None

	TRGT_TEXT	A text of up to 20 symbols sent directly to display. 
			Prior to that, a command for positioning and clearing 
			the lower line is sent.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_36_0_0.html">CMD_36_0_0</a></li></td>
					<td><pre>24H (36)	SET LAN SETTINGS

Works only with service jumper!!!
Returns current settings.

	Data field:		None

	Response:		IPAddr
			SubnetMask
			TCPPort
			DefGateway
			MACAddr

	IPAddr		4 numbers up to 255 separated with dot, represented device IP address.
	SubnetMask	4 numbers up to 255 separated with dot, represented device Subnet mask.
	TCPPort		4 numbers up to 255 separated with dot, represented device IP port.
	DefGateway	4 numbers up to 255 separated with dot, represented device Default Gateway.
	MACAddr	Up to 12 hexadecimals symbols represented device MAC address. 

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_36_0_1.html">CMD_36_0_1</a></li></td>
					<td><pre>24H (36)	SET LAN SETTINGS

Works only with service jumper!!!


	Data field:		
		IPAddr
		SubnetMask
		TCPPort
		DefGateway
		MACAddr

	Response:	
		None

	IPAddr		4 numbers up to 255 separated with dot, represented device IP address.
	SubnetMask	4 numbers up to 255 separated with dot, represented device Subnet mask.
	TCPPort		4 numbers up to 255 separated with dot, represented device IP port.
	DefGateway	4 numbers up to 255 separated with dot, represented device Default Gateway.
	MACAddr	Up to 12 hexadecimals symbols represented device MAC address. 
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_38_0_0.html">CMD_38_0_0</a></li></td>
					<td><pre>26h (38)	Open a non-fiscal receipt.

The FP performs the following actions:
	-	Prints the header
	-	Prints the tax registration number of the seller
	-	A response is received, which contains Allreceipt
The command cannot be executed, S1.1 is raised if.
	-	The fiscal memory has not been formatted
	-	There is an opened fiscal or non-fiscal receipt
	-	There is no paper
	-	The clock is not set
	-	The electronic journal is full

	Data field:
		None
	Response:	
		RecCnt
		GlobRecCnt

	RecCnt		Non-fiscal receipt count since last Z-report (4 bytes).
	GlobRecCnt	Global non-fiscal receipt count (after the fiscalisation) (8 bytes).

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_39_0_0.html">CMD_39_0_0</a></li></td>
					<td><pre>27h (39)	Closing a non-fiscal receipt


The FP performs the following actions:
Prints the footer
The sequence number, date and hour of document are printed
** NON-FISCAL RECEIPT **  is printed in expanded style.
If the S1.1 flag is raised, the command is not executed because there is no opened non-fiscal receipt.


	Data field:
			None
	Response:	
			RecCnt
			GlobRecCnt

	RecCnt		Non-fiscal receipt count since last Z-report (4 bytes).
	GlobRecCnt	Global non-fiscal receipt count (after the fiscalisation) (8 bytes).</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_41_0_0.html">CMD_41_0_0</a></li></td>
					<td><pre>29h (41)	SET MEMORY SWITCHES

	Data field:	Switches
	Response:	None

	Switches	8 bytes with value 0 or 1 - the configuration switches.

	The command writes to flash memory the switches value, graphics logo, barcode height, print 
	darkness and default drawer pulse length. After RAM reset they are restored with the saved values.
	If the switches parameter is not present, then the old switches are kept.


	***********************************************************************************
	Switch		OFF					ON
	***********************************************************************************
	8		Select RS232 speed 
	7		Select RS232 speed
	6		Select RS232 speed
	5		Not used
	4		Automatic paper cutting off		Automatic paper cutting on
	3		Half cut				Full cut
	2		Obligatory Display			No Obligatory Display
	1		Normal mode				Transparent display mode
	***********************************************************************************


	*************************************
	Sw8	Sw7	Sw6	Speed	
	*************************************
	0	0	0	1200 bps
	0	0	1	2400 bps
	0	1	0	4800 bps
	0	1	1	9600 bps
	1	0	0	19200 bps
	1	0	1	38400 bps
	1	1	0	57600 bps
	1	1	1	115200 bps
	**************************************

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_42_0_0.html">CMD_42_0_0</a></li></td>
					<td><pre>2Ah (42)	PRINTING OF A FREE NON-FISCAL TEXT
	
If S1.1 is raised, there is no non-fiscal receipt opened and the text is not printed.

	
	Data field:	Text
	Response:	None

	Text	A text of 42 symbols (at most). The symbols after 36 are cut off.

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_43_0_0.html">CMD_43_0_0</a></li></td>
					<td><pre>2Bh (43)	SETTING FOOTER AND PRINTING OPTIONS
	
	Data field:
		Item
		Text
	Response:	
		Entries from the data field

FOOTER consists of 2 lines of text printed at the end of each receipt.
HEADER and FOOTER are automatically center aligned.

Item		One symbol having the following meaning
"0".."5"		Selects the THE HEADER (any one of numbers will record the whole Header).
"6" or "7"		Selects the first or second FOOTER (TAX OFFICE) line.
"B"		Set bar code height in pixels (0.125 mm). Possible values from 24 (3 mm) to 240 (30 mm). 
		The barcode is printed with command 84 (54H).
"C"		Permission/rejection of the automatic cutting of paper after each receipt. After switching ON, the 
		performance of printer is defined in accordance with the setting of the switch SW1.
"D"		Set print darkness. Possible values: 
'1':		Very low
'2':		Low
'3':		Normal
'4':		Dark
'5':		Very dark
"L"		Height of graphic logo and permission/rejection of the printing of graphic logo immediately before the header. 
		This logo is defined with command 115 (73H).
"X"		Enable / disable automatic cash drawer pulse in commands 53 (35H) and 70 (46H).
"I"		Gives us the option to read values, set earlier with command 43. After the letter "I" only one more symbol 
		follows which coincides with some of the above.

Text		A text string:

If <Item> is '0'..'5' - 
LineX		The HEADER line, which is defined. Up to 48 bytes, but the total data length must be no more than 218 symbols. 
		Only the needed line count must be set (If the name and address did not require 6 lines).
Tab		Tabulation (ASCII code 09h).

The whole text of HEADER which will be writed in Fiscal Memory at once!!! Before the fiscalisation the header is not written to the 
fiscal memory and may be changed unlimited times. Command 72 (Fiscalisation) writes the first names record with the currently 
programmed header lines. After the fiscalisation 9 changes are allowed.

If <Item> is '6' or '7' - the text of the first or second footer line (up to 48 symbols).
If <Item> = 'B' - A number - the height of bar code in pixels.
If <Item> = 'C' - One symbol value '0' or '1', where "0" forbids and "1" permits the automatic cutting of the receipt.
If <Item> = 'D' - The print darkness (1 to 5).
If <Item> = `L' Syntax <Enabled>,<Height>

Enabled	'0' or '1', where '1' means, that logo printing is enabled.
Height	Graphics logo height in lines (0.125 mm). A number from 8 to 96.
If <Item> = 'X' - One symbol: '0' or '1', where '1' disables and '0' enables automatic cash drawer pulse in commands 53 (35H) and 
70 (46H).

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_43_0_1.html">CMD_43_0_1</a></li></td>
					<td><pre>2Bh (43)	SETTING FOOTER AND PRINTING OPTIONS
	
	Data field:
		Item
		Text
	Response:	
		Entries from the data field

FOOTER consists of 2 lines of text printed at the end of each receipt.
HEADER and FOOTER are automatically center aligned.

Item		One symbol having the following meaning
"0".."5"		Selects the THE HEADER (any one of numbers will record the whole Header).
"6" or "7"		Selects the first or second FOOTER (TAX OFFICE) line.
"B"		Set bar code height in pixels (0.125 mm). Possible values from 24 (3 mm) to 240 (30 mm). The barcode is 
		printed with command 84 (54H).
"C"		Permission/rejection of the automatic cutting of paper after each receipt. After switching ON, the performance 
		of printer is defined in accordance with the setting of the switch SW1.
"D"		Set print darkness. Possible values: 
'1':		Very low
'2':		Low
'3':		Normal
'4':		Dark
'5':		Very dark
"L"		Height of graphic logo and permission/rejection of the printing of graphic logo immediately before the header. 
		This logo is defined with command 115 (73H).
"X"		Enable / disable automatic cash drawer pulse in commands 53 (35H) and 70 (46H).
"I"		Gives us the option to read values, set earlier with command 43. After the letter "I" only one more symbol follows 
		which coincides with some of the above.

Text		A text string:
If <Item> is '0'..'5' 
LineX		The HEADER line, which is defined. Up to 48 bytes, but the total data length must be no more than 218 symbols. 
		Only the needed line count must be set (If the name and address did not require 6 lines).
Tab		Tabulation (ASCII code 09h).

The whole text of HEADER which will be writed in Fiscal Memory at once!!! Before the fiscalisation the header is not written to the fiscal 
memory and may be changed unlimited times. Command 72 (Fiscalisation) writes the first names record with the currently programmed 
header lines. After the fiscalisation 9 changes are allowed.

If <Item> is '6' or '7' - the text of the first or second footer line (up to 48 symbols).
If <Item> = 'B' - A number - the height of bar code in pixels.
If <Item> = 'C' - One symbol value '0' or '1', where "0" forbids and "1" permits the automatic cutting of the receipt.
If <Item> = 'D' - The print darkness (1 to 5).
If <Item> = `L' Syntax <Enabled>,<Height>

Enabled	'0' or '1', where '1' means, that logo printing is enabled.
Height	Graphics logo height in lines (0.125 mm). A number from 8 to 96.
If <Item> = 'X' - One symbol: '0' or '1', where '1' disables and '0' enables automatic cash drawer pulse in commands 53 (35H) 
and 70 (46H).
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_44_0_0.html">CMD_44_0_0</a></li></td>
					<td><pre>2Ch (44)		ADVANCING PAPER

	Data field:		Lines
	Response:		None
	
	Lines		Advancing paper measured in text lines. The programmed line count cannot be greater 
			than 99 (1 or 2 bytes).</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_45_0_0.html">CMD_45_0_0</a></li></td>
					<td><pre>2Dh (45)	CUTTING OFF PRINTED DOCUMENT

	Data field:		None
	Response:		None

The command causes the cutting off of the printed, ready document. It must be considered that the program 
must advance the paper with at least two lines or the document will not be cut off correctly. If the printer is in 
"automatic cut off" mode, it positions the paper itself and the command becomes redundant.
When the printing mechanism blocks for some reason, open the cover, remove the paper from the cutter region 
and switch the printer off and on. The cutter will go to it's home position and if not damaged, will be ready to use. </pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_47_0_0.html">CMD_47_0_0</a></li></td>
					<td><pre>2F (47)	DISPLAYING A TEXT ON THE UPPER LINE OF DISPLAY

	Data field:		Text
	Response:		None

	Text	A text of 20 symbols, which is sent directly to the display. Prior to that, a command for 
		positioning and clearing of the upper line. 
		If a fiscal receipt is opened and SW1 is OFF, the command is rejected.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_48_0_0.html">CMD_48_0_0</a></li></td>
					<td><pre>30h (48)	OPENING A FISCAL CLIENT'S RECEIPT

	Data field:
			OpCode
			OpPwd
			TillNmb
	Response:		
			RecCnt
			GlobRecCnt

	OpCode		Operator's number (1 to 16)
	OpPwd		Operator's password (4 to 8 digits)
	TillNmb		Number of point of sale (a whole number of maximum 5 digits)

	RecCnt		Fiscal receipt count since last Z-report (4 bytes).
	GlobRecCnt	Global fiscal receipt count (after the fiscalisation) (8 bytes).




The FP performs the following actions:
	Prints the HEADER
	Prints the tax registration number
	Prints the number and name of operator as well as the cashier desk number
	RecCnt and GlobRecCnt are returned 

The command will not be successful if:
	There is an opened fiscal or non-fiscal receipt
	The maximum number of receipts, as fixed for the day, has already been issued
	The fiscal memory is full
	The fiscal memory is damaged
	No code or operator password, or cashier desk number available
	The HEADER is not programmed
	No tax registration number available
	Wrong operator password
	The clock needs setting
	Journal is full
	After entering three wrong operator's passwords, the printer blocks and must be switched 
	off and on again to restart operation.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_48_0_1.html">CMD_48_0_1</a></li></td>
					<td><pre>30h (48)	OPENING A FISCAL CLIENT'S RECEIPT

	Data field:
		OpCode
		OpPwd
		TillNmb
		BuyerLine1
		BuyerLine2
		BuyerLine3
		TIN
		VRN
	Response:	
		RecCnt
		GlobRecCnt



	OpCode		Operator's number (1 to 16)
	OpPwd		Operator's password (4 to 8 digits)
	TillNmb		Number of point of sale (a whole number of maximum 5 digits)
	BuyerLineX	Buyer's 3 line info 
	TIN		Buyers tax identification number
	VRN		Buyers VAT identification number

	RecCnt		Fiscal receipt count since last Z-report (4 bytes).
	GlobRecCnt	Global fiscal receipt count (after the fiscalisation) (8 bytes).



The FP performs the following actions:
	Prints the HEADER
	Prints the tax registration number
	Prints the number and name of operator as well as the cashier desk number
	RecCnt and GlobRecCnt are returned 

The command will not be successful if:
	-	There is an opened fiscal or non-fiscal receipt;
	-	The maximum number of receipts, as fixed for the day, has already been issued;
	-	The fiscal memory is full;
	-	The fiscal memory is damaged;
	-	No code or operator password, or cashier desk number available;
	-	The HEADER is not programmed;
	-	No tax registration number available;
	-	Wrong operator password;
	-	The clock needs setting;
	-	Journal is full;
	-	After entering three wrong operator's passwords, the printer blocks and must be switched 
		off and on again to restart operation.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_49_0_0.html">CMD_49_0_0</a></li></td>
					<td><pre>31H (49)	REGISTRATION OF SALES

	Data field:
		TaxCd
		Price

	Response:	
		None



	TaxCd	One byte containing letter, which indicates the type of tax. There is a restriction, depending on the enabled 
		tax groups (command 83).
	Price	This is a singular price that consists of 8 meaningful digits. 

	

	FP performs the following actions:
		-	The text, describing sale is printed out together with the price and code of discount or surcharge. 
			If there is a set quantity, the information on it is printed out too.
		-	The price of the items sold is accumulated to the sums already stored in the operational memory. 
			In case of memory overflow the value of respective bites of the status field will be set.
		-	If there is a discount or surcharge, it is printed out on a separate line and is then added to a specially 
			maintained registers within the printer. 
			The values for the day are printed out together with the daily financial report.

	The command will not be correctly executed if and when:
		-	No fiscal receipt has been opened
		-	The maximum number of sales for one receipt have already been performed (512)
		-	The 35h command has been successfully executed
		-	The sum for some of the tax groups has become negative
		-	The sum of discounts and surcharges within the same receipt has become negative
		-	Journal is full
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_49_0_1.html">CMD_49_0_1</a></li></td>
					<td><pre>31H (49)	REGISTRATION OF SALES

	Data field:
		L1
		L2
		TaxCd
		Price
		Quan
		UN
		Perc

	Response:
		None

	L1	A text of up to 36 bytes containing one line of description of sale.
	L2	A text of up to 36 bytes containing a second line describing the sale.
	TaxCd	One byte containing letter, which indicates the type of tax. There is a restriction, depending on the enabled 
		tax groups (command 83).
	Price	This is a singular price that consists of 8 meaningful digits. 
	Quan	A non-mandatory parameter setting the quantity of items for sale. By default, this is 1.000.The length of this 
		parameter is 8 meaningful digits (not more than 3 after the decimal point). The result Price*Quan is rounded 
		up to the set number of digits and cannot be longer than 8 meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	Perc	This is a non-mandatory parameter which sets the value of discount or surcharge (depending on the sign) in 
		percent over the currently performed sale. Possible values are between - 99.00% and 99.00%, where up to 2 
		decimal places are acceptable.
	


	FP performs the following actions:
		-	The text, describing sale is printed out together with the price and code of discount or surcharge. 
			If there is a set quantity, the information on it is printed out too.
		-	The price of the items sold is accumulated to the sums already stored in the operational memory. 
			In case of memory overflow the value of respective bites of the status field will be set.
		-	If there is a discount or surcharge, it is printed out on a separate line and is then added to a specially 
			maintained registers within the printer. 
			The values for the day are printed out together with the daily financial report.

	The command will not be correctly executed if and when:
		-	No fiscal receipt has been opened
		-	The maximum number of sales for one receipt have already been performed (512)
		-	The 35h command has been successfully executed
		-	The sum for some of the tax groups has become negative
		-	The sum of discounts and surcharges within the same receipt has become negative
		-	Journal is full
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_49_0_2.html">CMD_49_0_2</a></li></td>
					<td><pre>31H (49)	REGISTRATION OF SALES

	Data field:
		L1
		L2
		TaxCd
		Price
		Quan
		UN
		AbsSum
	Response:	
		None

	L1	A text of up to 36 bytes containing one line of description of sale.
	L2	A text of up to 36 bytes containing a second line describing the sale.
	TaxCd	One byte containing letter, which indicates the type of tax. There is a restriction, depending on the enabled 
		tax groups (command 83).
	Price	This is a singular price that consists of 8 meaningful digits. 
	Quan	A non-mandatory parameter setting the quantity of items for sale. By default, this is 1.000.The length of this 
		parameter is 8 meaningful digits (not more than 3 after the decimal point). The result Price*Quan is rounded 
		up to the set number of digits and cannot be longer than 8 meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	AbsSum	This is a non-mandatory parameter which sets the value of discount or surcharge (depending on the sign) over 
		the currently performed sale. Up to 8 significant digits.
	


	FP performs the following actions:
		-	The text, describing sale is printed out together with the price and code of discount or surcharge. 
			If there is a set quantity, the information on it is printed out too.
		-	The price of the items sold is accumulated to the sums already stored in the operational memory. 
			In case of memory overflow the value of respective bites of the status field will be set.
		-	If there is a discount or surcharge, it is printed out on a separate line and is then added to a specially 
			maintained registers within the printer. 
			The values for the day are printed out together with the daily financial report.

	The command will not be correctly executed if and when:
		-	No fiscal receipt has been opened
		-	The maximum number of sales for one receipt have already been performed (512)
		-	The 35h command has been successfully executed
		-	The sum for some of the tax groups has become negative
		-	The sum of discounts and surcharges within the same receipt has become negative
		-	Journal is full
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_49_0_3.html">CMD_49_0_3</a></li></td>
					<td><pre>31H (49)	REGISTRATION OF SALES

	Data field:
		L1
		TaxCd
		Price
		Quan
		UN
		AbsSum

	Response:
		None

	L1	A text of up to 36 bytes containing one line of description of sale.
	TaxCd	One byte containing letter, which indicates the type of tax. There is a restriction, depending on the enabled 
		tax groups (command 83).
	Price	This is a singular price that consists of 8 meaningful digits. 
	Quan	A non-mandatory parameter setting the quantity of items for sale. By default, this is 1.000.The length of this 
		parameter is 8 meaningful digits (not more than 3 after the decimal point). The result Price*Quan is rounded 
		up to the set number of digits and cannot be longer than 8 meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	AbsSum	This is a non-mandatory parameter which sets the value of discount or surcharge (depending on the sign) over 
		the currently performed sale. Up to 8 significant digits.
	


	FP performs the following actions:
		-	The text, describing sale is printed out together with the price and code of discount or surcharge. 
			If there is a set quantity, the information on it is printed out too.
		-	The price of the items sold is accumulated to the sums already stored in the operational memory. 
			In case of memory overflow the value of respective bites of the status field will be set.
		-	If there is a discount or surcharge, it is printed out on a separate line and is then added to a specially 
			maintained registers within the printer. 
			The values for the day are printed out together with the daily financial report.

	The command will not be correctly executed if and when:
		-	No fiscal receipt has been opened
		-	The maximum number of sales for one receipt have already been performed (512)
		-	The 35h command has been successfully executed
		-	The sum for some of the tax groups has become negative
		-	The sum of discounts and surcharges within the same receipt has become negative
		-	Journal is full
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_49_0_4.html">CMD_49_0_4</a></li></td>
					<td><pre>31H (49)	REGISTRATION OF SALES

	Data field:
		TaxCd
		Price
		Quan
		UN
		AbsSum
	Response:	
		None



	TaxCd	One byte containing letter, which indicates the type of tax. There is a restriction, depending on the enabled 
		tax groups (command 83).
	Price	This is a singular price that consists of 8 meaningful digits. 
	Quan	A non-mandatory parameter setting the quantity of items for sale. By default, this is 1.000.The length of this 
		parameter is 8 meaningful digits (not more than 3 after the decimal point). The result Price*Quan is rounded 
		up to the set number of digits and cannot be longer than 8 meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	AbsSum	This is a non-mandatory parameter which sets the value of discount or surcharge (depending on the sign) over 
		the currently performed sale. Up to 8 significant digits.
	


	FP performs the following actions:
		-	The text, describing sale is printed out together with the price and code of discount or surcharge. 
			If there is a set quantity, the information on it is printed out too.
		-	The price of the items sold is accumulated to the sums already stored in the operational memory. 
			In case of memory overflow the value of respective bites of the status field will be set.
		-	If there is a discount or surcharge, it is printed out on a separate line and is then added to a specially 
			maintained registers within the printer. 
			The values for the day are printed out together with the daily financial report.

	The command will not be correctly executed if and when:
		-	No fiscal receipt has been opened
		-	The maximum number of sales for one receipt have already been performed (512)
		-	The 35h command has been successfully executed
		-	The sum for some of the tax groups has become negative
		-	The sum of discounts and surcharges within the same receipt has become negative
		-	Journal is full
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_49_0_5.html">CMD_49_0_5</a></li></td>
					<td><pre>31H (49)	REGISTRATION OF SALES

	Data field:
		L2
		TaxCd
		Price
		Quan
		UN
		AbsSum
	Response:	
		None


	L2	A text of up to 36 bytes containing a second line describing the sale.
	TaxCd	One byte containing letter, which indicates the type of tax. There is a restriction, depending on the enabled 
		tax groups (command 83).
	Price	This is a singular price that consists of 8 meaningful digits. 
	Quan	A non-mandatory parameter setting the quantity of items for sale. By default, this is 1.000.The length of this 
		parameter is 8 meaningful digits (not more than 3 after the decimal point). The result Price*Quan is rounded 
		up to the set number of digits and cannot be longer than 8 meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	AbsSum	This is a non-mandatory parameter which sets the value of discount or surcharge (depending on the sign) 
		over the currently performed sale. Up to 8 significant digits.
	


	FP performs the following actions:
		-	The text, describing sale is printed out together with the price and code of discount or surcharge. 
			If there is a set quantity, the information on it is printed out too.
		-	The price of the items sold is accumulated to the sums already stored in the operational memory. 
			In case of memory overflow the value of respective bites of the status field will be set.
		-	If there is a discount or surcharge, it is printed out on a separate line and is then added to a specially 
			maintained registers within the printer. 
			The values for the day are printed out together with the daily financial report.

	The command will not be correctly executed if and when:
		-	No fiscal receipt has been opened
		-	The maximum number of sales for one receipt have already been performed (512)
		-	The 35h command has been successfully executed
		-	The sum for some of the tax groups has become negative
		-	The sum of discounts and surcharges within the same receipt has become negative
		-	Journal is full
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_49_0_6.html">CMD_49_0_6</a></li></td>
					<td><pre>31H (49)	REGISTRATION OF SALES

	Data field:
		L1
		TaxCd
		Price
		Quan
		UN
		Perc
	Response:	
		None

	L1	A text of up to 36 bytes containing one line of description of sale.
	TaxCd	One byte containing letter, which indicates the type of tax. There is a restriction, depending on the enabled 
		tax groups (command 83).
	Price	This is a singular price that consists of 8 meaningful digits. 
	Quan	A non-mandatory parameter setting the quantity of items for sale. By default, this is 1.000.The length of this 
		parameter is 8 meaningful digits (not more than 3 after the decimal point). The result Price*Quan is rounded 
		up to the set number of digits and cannot be longer than 8 meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	Perc	This is a non-mandatory parameter which sets the value of discount or surcharge (depending on the sign) in 
		percent over the currently performed sale. Possible values are between - 99.00% and 99.00%, where up to 2 
		decimal places are acceptable.
	


	FP performs the following actions:
		-	The text, describing sale is printed out together with the price and code of discount or surcharge. 
			If there is a set quantity, the information on it is printed out too.
		-	The price of the items sold is accumulated to the sums already stored in the operational memory. 
			In case of memory overflow the value of respective bites of the status field will be set.
		-	If there is a discount or surcharge, it is printed out on a separate line and is then added to a specially 
			maintained registers within the printer. 
			The values for the day are printed out together with the daily financial report.

	The command will not be correctly executed if and when:
		-	No fiscal receipt has been opened
		-	The maximum number of sales for one receipt have already been performed (512)
		-	The 35h command has been successfully executed
		-	The sum for some of the tax groups has become negative
		-	The sum of discounts and surcharges within the same receipt has become negative
		-	Journal is full
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_49_0_7.html">CMD_49_0_7</a></li></td>
					<td><pre>31H (49)	REGISTRATION OF SALES

	Data field:
		L2
		TaxCd
		Price
		Quan
		UN
		Perc
	Response:
		None


	L2	A text of up to 36 bytes containing a second line describing the sale.
	TaxCd	One byte containing letter, which indicates the type of tax. There is a restriction, depending on the enabled 
		tax groups (command 83).
	Price	This is a singular price that consists of 8 meaningful digits. 
	Quan	A non-mandatory parameter setting the quantity of items for sale. By default, this is 1.000.The length of this 
		parameter is 8 meaningful digits (not more than 3 after the decimal point). The result Price*Quan is rounded 
		up to the set number of digits and cannot be longer than 8 meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	Perc	This is a non-mandatory parameter which sets the value of discount or surcharge (depending on the sign) in 
		percent over the currently performed sale. Possible values are between - 99.00% and 99.00%, where up to 2 
		decimal places are acceptable.
	


	FP performs the following actions:
		-	The text, describing sale is printed out together with the price and code of discount or surcharge. 
			If there is a set quantity, the information on it is printed out too.
		-	The price of the items sold is accumulated to the sums already stored in the operational memory. 
			In case of memory overflow the value of respective bites of the status field will be set.
		-	If there is a discount or surcharge, it is printed out on a separate line and is then added to a specially 
			maintained registers within the printer. 
			The values for the day are printed out together with the daily financial report.

	The command will not be correctly executed if and when:
		-	No fiscal receipt has been opened
		-	The maximum number of sales for one receipt have already been performed (512)
		-	The 35h command has been successfully executed
		-	The sum for some of the tax groups has become negative
		-	The sum of discounts and surcharges within the same receipt has become negative
		-	Journal is full
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_49_0_8.html">CMD_49_0_8</a></li></td>
					<td><pre>31H (49)	REGISTRATION OF SALES

	Data field:
		TaxCd
		Price
		Quan
		UN
		Perc
	Response:	
		None


	TaxCd	One byte containing letter, which indicates the type of tax. There is a restriction, depending on the enabled 
		tax groups (command 83).
	Price	This is a singular price that consists of 8 meaningful digits. 
	Quan	A non-mandatory parameter setting the quantity of items for sale. By default, this is 1.000.The length of this 
		parameter is 8 meaningful digits (not more than 3 after the decimal point). The result Price*Quan is rounded 
		up to the set number of digits and cannot be longer than 8 meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	Perc	This is a non-mandatory parameter which sets the value of discount or surcharge (depending on the sign) in 
		percent over the currently performed sale. Possible values are between - 99.00% and 99.00%, where up to 2
		decimal places are acceptable.
	


	FP performs the following actions:
		-	The text, describing sale is printed out together with the price and code of discount or surcharge. 
			If there is a set quantity, the information on it is printed out too.
		-	The price of the items sold is accumulated to the sums already stored in the operational memory. 
			In case of memory overflow the value of respective bites of the status field will be set.
		-	If there is a discount or surcharge, it is printed out on a separate line and is then added to a specially 
			maintained registers within the printer. 
			The values for the day are printed out together with the daily financial report.

	The command will not be correctly executed if and when:
		-	No fiscal receipt has been opened
		-	The maximum number of sales for one receipt have already been performed (512)
		-	The 35h command has been successfully executed
		-	The sum for some of the tax groups has become negative
		-	The sum of discounts and surcharges within the same receipt has become negative
		-	Journal is full
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_50_0_0.html">CMD_50_0_0</a></li></td>
					<td><pre>32h (50)	TAX RATES ENTERED DURING THE ACCOUNTED PERIOD

	Data field:
		StartDate
		EndDate
	Response:	
		Data

	StartDate		The starting date of the period - DDMMYY/6 bytes/
	EndDate		The end date of the period - DDMMYY /6 bytes/

	Data	
			'F' if no tax rates for the period have been found, or in case of error
			'PAA,BB,CC,DD,DDMMYY' if rates have been found, where 'P' means 'PASS' after which the last 
			active rates for the period are listed out as well as the date of their entry. If there are unused groups 
			(disabled by command 83) for them, instead of rate in percent a 'DT' is returned (Disabled tax).

			When Start and End are entered, the comma is mandatory.
			The command prints a report on the changes made in the decimal points and tax rates during the 
			selected period.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_51_0_0.html">CMD_51_0_0</a></li></td>
					<td><pre>33h (51)	SUBTOTAL
	
	Data field:
		Print
		Display
	Response:	
		SubTotal
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF

	ToPrint	One byte, which if '1' the sum of the subtotal will be printed out.
	Display	One byte which if '1' the sum of the subtotal will appear on display.

	SubTotal	The sum accumulated for the current fiscal receipt (10 bytes).
	TaxA	The sum over tax group A /10 bytes/
	TaxB	The sum over tax group B /10 bytes/
	TaxC	The sum over tax group C /10 bytes/
	TaxD	The sum over tax group D /10 bytes/
	TaxE	The sum over tax group E /10 bytes/
	TaxF	The sum over tax group F /10 bytes/
	
The sum of all sales registered in the fiscal receipt is calculated. If necessary, the sum may be printed out and/or 
brought out on display. 

The calculated total sum and the accumulated separate sums for each tax group are returned to the PC. 
If a discount or surcharge is entered, it is printed out on a separate line and the accumulated sums over the different 
tax groups are respectively corrected.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_51_0_1.html">CMD_51_0_1</a></li></td>
					<td><pre>33h (51)	SUBTOTAL
	
	Data field:
		Print
		Display
		Perc
	Response:	
		SubTotal
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF

	ToPrint	One byte, which if '1' the sum of the subtotal will be printed out.
	Display	One byte which if '1' the sum of the subtotal will appear on display.
	Perc	Shows the value of discount or surcharge in percent over the sum accumulated so far.

	SubTotal	The sum accumulated for the current fiscal receipt (10 bytes).
	TaxA	The sum over tax group A /10 bytes/
	TaxB	The sum over tax group B /10 bytes/
	TaxC	The sum over tax group C /10 bytes/
	TaxD	The sum over tax group D /10 bytes/
	TaxE	The sum over tax group E /10 bytes/
	TaxF	The sum over tax group F /10 bytes/
	
The sum of all sales registered in the fiscal receipt is calculated. If necessary, the sum may be printed out and/or 
brought out on display. 

The calculated total sum and the accumulated separate sums for each tax group are returned to the PC. 

If a discount or surcharge is entered, it is printed out on a separate line and the accumulated sums over the different 
tax groups are respectively corrected.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_51_0_2.html">CMD_51_0_2</a></li></td>
					<td><pre>33h (51)	SUBTOTAL
	
	Data field:
		Print
		Display
		AbsSum
	Response:	
		SubTotal
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF

	ToPrint	One byte, which if '1' the sum of the subtotal will be printed out.
	Display	One byte which if '1' the sum of the subtotal will appear on display.
	AbsSum	A non-mandatory parameter, which shows the value of discount as absolute value (up to 8 digits).

	SubTotal	The sum accumulated for the current fiscal receipt (10 bytes).
	TaxA	The sum over tax group A /10 bytes/
	TaxB	The sum over tax group B /10 bytes/
	TaxC	The sum over tax group C /10 bytes/
	TaxD	The sum over tax group D /10 bytes/
	TaxE	The sum over tax group E /10 bytes/
	TaxF	The sum over tax group F /10 bytes/
	
The sum of all sales registered in the fiscal receipt is calculated. If necessary, the sum may be printed out and/or brought out 
on display. 

The calculated total sum and the accumulated separate sums for each tax group are returned to the PC. 
If a discount or surcharge is entered, it is printed out on a separate line and the accumulated sums over the different tax groups 
are respectively corrected.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_52_0_0.html">CMD_52_0_0</a></li></td>
					<td><pre>34H (52)	REGISTRATION AND DISPLAY

	Data field:
		TaxCd
		Price
	Response:	
		None

	Tab	One byte containing 09h
	TaxCd	One byte containing letter that indicates the tax group ('A', 'B', 'C', 'D', 'E', 'F'). There is a restriction, which 
		depends on disabled taxes (command 83).
	Price	This is the price - up to 8 valid digits.

	The fiscal printer will:
	-	Print out the text describing the sale together with the price and the code of the tax group.
	-	The price of the item sold is added to the accumulated sums in the registries of operational memory. In case of 
		overflow, the respective bits of status bytes are set.
	-	If there is a surcharge or discount made on the sum, it is printed out on a separate line and is added to 
		registries, specially reserved in the printer. The daily accumulated sums are printed out together with the daily 
		financial report.
	
	
	The command will not be executed successfully if:
	-	No fiscal memory has been opened
	-	The maximum possible number of sales have already been performed
	-	The command 53 (34H) has been successfully executed
	-	The sum under some of the tax groups has become negative
	-	The sum of the surcharge or discount within the receipt remains negative
	-	The journal is full

The price of the item is shown on the upper line of display and its description - on the lower.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_52_0_1.html">CMD_52_0_1</a></li></td>
					<td><pre>34H (52)	REGISTRATION AND DISPLAY

	Data field:	
		Line
		TaxCd
		Price
		Quan
		UN
		Perc
	Response:	
		None


	Line	A 20 byte string containing text, which describes the sale.
	TaxCd	One byte containing letter that indicates the tax group ('A', 'B', 'C', 'D', 'E', 'F'). There is a restriction, which 
		depends on disabled taxes (command 83).
	Sign	One byte with a value of '-'.
	Price	This is the price - up to 8 valid digits
	Quan	This is a non-mandatory parameter setting the quantity of the items sold. By default its value is 1.000 and its 
		length - 8 valid digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	Perc	Parameter showing the value of surcharge and discount (depending on the sign) in percent over the current sale. 
		Possible values are between -99.00% to 99.00%. 

	The fiscal printer will:
	-	Print out the text describing the sale together with the price and the code of the tax group.
	-	The price of the item sold is added to the accumulated sums in the registries of operational memory. In case of 
		overflow, the respective bits of status bytes are set.
	-	If there is a surcharge or discount made on the sum, it is printed out on a separate line and is added to 
		registries, specially reserved in the printer. The daily accumulated sums are printed out together with the daily 
		financial report.
	
	
	The command will not be executed successfully if:
	-	No fiscal memory has been opened
	-	The maximum possible number of sales have already been performed
	-	The command 53 (34H) has been successfully executed
	-	The sum under some of the tax groups has become negative
	-	The sum of the surcharge or discount within the receipt remains negative
	-	The journal is full

The price of the item is shown on the upper line of display and its description - on the lower.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_52_0_2.html">CMD_52_0_2</a></li></td>
					<td><pre>34H (52)	REGISTRATION AND DISPLAY

	Data field:
		Line
		TaxCd
		Price
		Quan
		UN
		AbsSum
	Response:
		None

	Line	A 20 byte string containing text, which describes the sale.
	TaxCd	One byte containing letter that indicates the tax group ('A', 'B', 'C', 'D', 'E', 'F'). There is a restriction, which 
		depends on disabled taxes (command 83).
	Sign	One byte with a value of '-'.
	Price	This is the price - up to 8 valid digits
	Quan	This is a non-mandatory parameter setting the quantity of the items sold. By default its value is 1.000 and its 
		length - 8 valid digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	AbsSum	Parameter which sets the value of discount or surcharge (depending on the sign) over the currently performed 
		sale.  Up to 8 significant digits. 

	The fiscal printer will:
	-	Print out the text describing the sale together with the price and the code of the tax group.
	-	The price of the item sold is added to the accumulated sums in the registries of operational memory. In case of 
		overflow, the respective bits of status bytes are set.
	-	If there is a surcharge or discount made on the sum, it is printed out on a separate line and is added to 
		registries, specially reserved in the printer. The daily accumulated sums are printed out together with the daily 
		financial report.
	
	
	The command will not be executed successfully if:
	-	No fiscal memory has been opened
	-	The maximum possible number of sales have already been performed
	-	The command 53 (34H) has been successfully executed
	-	The sum under some of the tax groups has become negative
	-	The sum of the surcharge or discount within the receipt remains negative
	-	The journal is full

The price of the item is shown on the upper line of display and its description - on the lower.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_53_0_0.html">CMD_53_0_0</a></li></td>
					<td><pre>35H (53)	CALCULATION OF A TOTAL

	Data field:
		PaidMode
		Sign
		Amount_In
	Resonse:	
		PaidCode
		Amount_Out

	PaidMode		A non-mandatory code indicating the terms of payment. It may have the following values:
			'P' 	Payment in cash
			'N' 	Payment via credit
			'C' 	Payment in cheques
			'D' 	Payment with a debit card
			'I'	Programmable payment 1
			'J'	Programmable payment 2
			'K'	Programmable payment 3
			'L'	Programmable payment 4

	Depending on the code, the sums are accumulated in different registers and may be recovered in the daily report.

	Sign		One byte with a value '+' indicating the Amount (the sum which has to be tendered)
	Amount_In	The sum tendered (up to 9 meaningful symbols)


	PaidCode		One byte - resulting from the execution of the command
			'F'	Error
			'E'	The calculated sub-total sum is negative. Payment is withheld and Amount will 
				contain a negative sub-total.
			'D'	If the paid sum is less than the sum on the receipt. The residual sum due for payment 
				is returned to Amount
			'R'	When the paid sum is greater than the sum on the receipt. A message "CHANGE" will 
				be printed out and the change will be returned to Amount.
			'I'	An error has occurred because the sum under one of the tax groups is negative. The 
				current subtotal is returned to Amount.
	Amount_Out	Up to 9 digits with a sign. Depends on PaidCode.

	This command starts the calculation of the sums from fiscal receipt, the printing of the sum with a special font and 
	showing the result on display. An additional text may also be printed. When the command has been successfully 
	executed a further command for opening a cash drawer is activated. If there is no input data, the printer will automatically 
	pay out the whole available sum in cash.

	The command will not be successful if:
	-	No fiscal receipt has been opened,
	-	The accumulated sum is negative,
	-	If some of the accumulated sums under taxation (tax group) is negative.
	
	After the successful completion of the command, fiscal printer will not perform the commands 49 and 51 within the 
	opened receipt, although it can still perform command 53.

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_53_0_1.html">CMD_53_0_1</a></li></td>
					<td><pre>35H (53)	CALCULATION OF A TOTAL

	Data field:	
		None
	Resonse:	
		PaidCode
		Amount_Out

	

	PaidCode		One byte - resulting from the execution of the command
			'F'	Error
			'E'	The calculated sub-total sum is negative. Payment is withheld and Amount will contain a 
				negative sub-total.
			'D'	If the paid sum is less than the sum on the receipt. The residual sum due for payment is 
				returned to Amount
			'R'	When the paid sum is greater than the sum on the receipt. A message "CHANGE" will be 
				printed out and the change will be returned to Amount.
			'I'	An error has occurred because the sum under one of the tax groups is negative. The current 
				subtotal is returned to Amount.
		Amount_Out	Up to 9 digits with a sign. Depends on PaidCode.

	This command starts the calculation of the sums from fiscal receipt, the printing of the sum with a special font and showing 
	the result on display. An additional text may also be printed. When the command has been successfully executed a further 
	command for opening a cash drawer is activated. If there is no input data, the printer will automatically pay out the whole 
	available sum in cash.

	The command will not be successful if:
	-	No fiscal receipt has been opened,
	-	The accumulated sum is negative,
	-	If some of the accumulated sums under taxation (tax group) is negative.
	
	After the successful completion of the command, fiscal printer will not perform the commands 49 and 51 within the opened 
	receipt, although it can still perform command 53.

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_53_0_2.html">CMD_53_0_2</a></li></td>
					<td><pre>35H (53)	CALCULATION OF A TOTAL

	Data field:	
		PaidMode
	Resonse:	
		PaidCode
		Amount_Out

	PaidMode		A non-mandatory code indicating the terms of payment. It may have the following values:
			'P' 	Payment in cash
			'N' 	Payment via credit
			'C' 	Payment in cheques
			'D' 	Payment with a debit card
			'I'	Programmable payment 1
			'J'	Programmable payment 2
			'K'	Programmable payment 3
			'L'	Programmable payment 4

	Depending on the code, the sums are accumulated in different registers and may be recovered in the daily report.


	PaidCode		One byte - resulting from the execution of the command
			'F'	Error
			'E'	The calculated sub-total sum is negative. Payment is withheld and Amount will contain 
				a negative sub-total.
			'D'	If the paid sum is less than the sum on the receipt. The residual sum due for payment is 
				returned to Amount
			'R'	When the paid sum is greater than the sum on the receipt. A message "CHANGE" will 
				be printed out and the change will be returned to Amount.
			'I'	An error has occurred because the sum under one of the tax groups is negative. The 
				current subtotal is returned to Amount.
	Amount_Out	Up to 9 digits with a sign. Depends on PaidCode.


	This command starts the calculation of the sums from fiscal receipt, the printing of the sum with a special font and showing 
	the result on display. 	An additional text may also be printed.
	When the command has been successfully executed a further command for opening a cash drawer is activated. If there is no 
	input data, the printer will automatically pay out the whole available sum in cash.

	The command will not be successful if:
	-	No fiscal receipt has been opened,
	-	The accumulated sum is negative,
	-	If some of the accumulated sums under taxation (tax group) is negative.
	
	After the successful completion of the command, fiscal printer will not perform the commands 49 and 51 within the opened 
	receipt, although it can still perform command 53.

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_53_0_3.html">CMD_53_0_3</a></li></td>
					<td><pre>35H (53)	CALCULATION OF A TOTAL

	Data field:
		Amount_In
	Resonse:	
		PaidCode
		Amount_Out

	Amount_In	The sum tendered (up to 9 meaningful symbols)


	PaidCode	One byte - resulting from the execution of the command
		'F'	Error
		'E'	The calculated sub-total sum is negative. Payment is withheld and Amount will contain a 
			negative sub-total.
		'D'	If the paid sum is less than the sum on the receipt. The residual sum due for payment is returned 
			to Amount
		'R'	When the paid sum is greater than the sum on the receipt. A message "CHANGE" will be printed 
			out and the change will be returned to Amount.
		'I'	An error has occurred because the sum under one of the tax groups is negative. The current subtotal 
			is returned to Amount.
	Amount_Out	Up to 9 digits with a sign. Depends on PaidCode.

	This command starts the calculation of the sums from fiscal receipt, the printing of the sum with a special font and showing 
	the result on display. An additional text may also be printed.
	When the command has been successfully executed a further command for opening a cash drawer is activated. If there is no 
	input data, the printer will automatically pay out the whole available sum in cash.

	The command will not be successful if:
	-	No fiscal receipt has been opened,
	-	The accumulated sum is negative,
	-	If some of the accumulated sums under taxation (tax group) is negative.
	
	After the successful completion of the command, fiscal printer will not perform the commands 49 and 51 within the opened 
	receipt, although it can still perform command 53.

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_54_0_0.html">CMD_54_0_0</a></li></td>
					<td><pre>36H (54)	PRINTING A FREE FISCAL TEXT

	Data field:	
		Input_Text
	Response:	
		None

	Input_Text	Up to 42 bytes text

	A fiscal receipt must be opened because, in the opposite case, the text will not be printed and the S1.1. 
	flag is raised. If the text is longer than 42 symbols, the redundant letters are cut off. 
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_56_0_0.html">CMD_56_0_0</a></li></td>
					<td><pre>38H (56)	CLOSING A FISCAL RECEIPT

	Data field:	
		No data
	Response:	
		RecCnt
		GlobRecCnt

	RecCnt		Fiscal or refund receipt count since last Z-report (4 bytes).
	GlobRecCnt	Global fiscal or refund receipt count (after the fiscalisation) (8 bytes).

	The accumulated sums from the fiscal receipt are added to the daily sums in the registries of operational 
	memory.

	The command will not be successful if:
	-	No fiscal receipt has been opened,
	-	Command 53 (35h) has failed,
	-	The sum paid under command 53 is less than the total sum on the fiscal receipt.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_58_0_0.html">CMD_58_0_0</a></li></td>
					<td><pre>3AH (58)	REGISTERING THE SALE OF AN ITEM

	Data field:	
		PLU
		Quan
		UN
		Perc
	Response:		
		None

	PLU	The individual number of the item - a whole number between 1 and 999999999 (not more than 9 digits).
	Quan	Parameter setting the quantity of the items for sale with a default value of 1.000. Length cannot be longer 
		than 8 meaningful digits (not more than 3 after the decimal point). The resulting singular price (*Quan) is 
		rounded up to the set number of digits 
		after the decimal point and also cannot be greater than 8 meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	Perc	Parameter showing the value of surcharge or discount (depending on the symbol) in percent over the 
		current sale. Possible values are between -99.00% to 99.00%. Up to 2 digits after the decimal point are 
		acceptable.


	The fiscal printer performs the following operations:
	-	The name, price and tax group of the item is read from items list, programmed in the printer.
	-	Prints out the name of the item, selected quantity and singular price. The second printed line contains 
		the final price together with the letter, designating the tax group from which the sale will be performed. 
		The registries for accumulated sums and item quantities are updated. 
	-	The price of the item is added to the accumulated sums in the registries of operational memory. In case 
		of overflow, the respective bytes from the status field will be set.
	-	If there is a discount or surcharge, it is printed out on a separate line and is added in specially selected 
		registries in the printer. The values from the whole day will be printed together with the daily financial 
		report.
	The command will not be successful if:
	-	No item has been programmed under the given number,
	-	No fiscal receipt has been opened,
	-	The maximum number of sales for one receipt (512) has already been registered.
	-	The command 35h has been successfully executed,
	-	The sum under one or more of the tax groups has turned out negative,
	-	The sum of surcharges and discounts within the receipt has remained negative,
	-	The journal is full</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_58_0_1.html">CMD_58_0_1</a></li></td>
					<td><pre>3AH (58)	REGISTERING THE SALE OF AN ITEM

	Data field:	
		PLU
		Quan
		UN
		AbsSum
	Response:	
		None

	PLU	The individual number of the item - a whole number between 1 and 999999999 (not more than 9 digits).
	Quan	Parameter setting the quantity of the items for sale with a default value of 1.000. Length cannot be longer 
		than 8 meaningful digits (not more than 3 after the decimal point). The resulting singular price (*Quan) is 
		rounded up to the set number of digits after the decimal point and also cannot be greater than 8 
		meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".
	AbsSum	Parameter which sets the value of discount or surcharge (depending on the sign) over the current sale. 
		Up to 8 significant digits. 




	The fiscal printer performs the following operations:
	-	The name, price and tax group of the item is read from items list, programmed in the printer.
	-	Prints out the name of the item, selected quantity and singular price. The second printed line contains 
		the final price together with the letter, designating the tax group from which the sale will be performed. 
		The registries for accumulated sums and item quantities are updated. 
	-	The price of the item is added to the accumulated sums in the registries of operational memory. In case 
		of overflow, the respective bytes from the status field will be set.
	-	If there is a discount or surcharge, it is printed out on a separate line and is added in specially selected 
		registries in the printer. The values from the whole day will be printed together with the daily financial 
		report.
	The command will not be successful if:
	-	No item has been programmed under the given number,
	-	No fiscal receipt has been opened,
	-	The maximum number of sales for one receipt (512) has already been registered.
	-	The command 35h has been successfully executed,
	-	The sum under one or more of the tax groups has turned out negative,
	-	The sum of surcharges and discounts within the receipt has remained negative,
	-	The journal is full</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_58_0_2.html">CMD_58_0_2</a></li></td>
					<td><pre>3AH (58)	REGISTERING THE SALE OF AN ITEM

	Data field:	
		PLU
		Quan
		UN
	Response:	
		None

	PLU	The individual number of the item - a whole number between 1 and 999999999 (not more than 9 digits).
	Quan	Parameter setting the quantity of the items for sale with a default value of 1.000. Length cannot be longer 
		than 8 meaningful digits (not more than 3 after the decimal point). The resulting singular price (*Quan) is 
		rounded up to the set number of digits after the decimal point and also cannot be greater than 8 
		meaningful digits.
	UN	Unit name. A optional text up to 8 characters, describing the unit of the quantity, for example "kg".



	The fiscal printer performs the following operations:
	-	The name, price and tax group of the item is read from items list, programmed in the printer.
	-	Prints out the name of the item, selected quantity and singular price. The second printed line contains 
		the final price together with the letter, designating the tax group from which the sale will be performed. 
		The registries for accumulated sums and item quantities are updated. 
	-	The price of the item is added to the accumulated sums in the registries of operational memory. In case 
		of overflow, the respective bytes from the status field will be set.
	-	If there is a discount or surcharge, it is printed out on a separate line and is added in specially selected 
		registries in the printer. The values from the whole day will be printed together with the daily financial 
		report.
	The command will not be successful if:
	-	No item has been programmed under the given number,
	-	No fiscal receipt has been opened,
	-	The maximum number of sales for one receipt (512) has already been registered.
	-	The command 35h has been successfully executed,
	-	The sum under one or more of the tax groups has turned out negative,
	-	The sum of surcharges and discounts within the receipt has remained negative,
	-	The journal is full</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_58_0_3.html">CMD_58_0_3</a></li></td>
					<td><pre>3AH (58)	REGISTERING THE SALE OF AN ITEM

	Data field:	
		PLU
		Quan
	Response:	
		None

	PLU	The individual number of the item - a whole number between 1 and 999999999 (not more than 9 digits).
	Quan	Parameter setting the quantity of the items for sale with a default value of 1.000. Length cannot be longer 
		than 8 meaningful digits (not more than 3 after the decimal point). The resulting singular price (*Quan) is 
		rounded up to the set number of digits after the decimal point and also cannot be greater than 8 
		meaningful digits.


	The fiscal printer performs the following operations:
	-	The name, price and tax group of the item is read from items list, programmed in the printer.
	-	Prints out the name of the item, selected quantity and singular price. The second printed line contains 
		the final price together with the letter, designating the tax group from which the sale will be performed. 
		The registries for accumulated sums and item quantities are updated. 
	-	The price of the item is added to the accumulated sums in the registries of operational memory. In case 
		of overflow, the respective bytes from the status field will be set.
	-	If there is a discount or surcharge, it is printed out on a separate line and is added in specially selected 
		registries in the printer. The values from the whole day will be printed together with the daily financial 
		report.
	The command will not be successful if:
	-	No item has been programmed under the given number,
	-	No fiscal receipt has been opened,
	-	The maximum number of sales for one receipt (512) has already been registered.
	-	The command 35h has been successfully executed,
	-	The sum under one or more of the tax groups has turned out negative,
	-	The sum of surcharges and discounts within the receipt has remained negative,
	-	The journal is full</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_58_0_4.html">CMD_58_0_4</a></li></td>
					<td><pre>3AH (58)	REGISTERING THE SALE OF AN ITEM

	Data field:	
		PLU
		Quan
	Response:	
		None

	PLU	The individual number of the item - a whole number between 1 and 999999999 (not more than 9 digits).


	The fiscal printer performs the following operations:
	-	The name, price and tax group of the item is read from items list, programmed in the printer.
	-	Prints out the name of the item, selected quantity and singular price. The second printed line contains 
		the final price together with the letter, designating the tax group from which the sale will be performed. 
		The registries for accumulated sums and item quantities are updated. 
	-	The price of the item is added to the accumulated sums in the registries of operational memory. In case 
		of overflow, the respective bytes from the status field will be set.
	-	If there is a discount or surcharge, it is printed out on a separate line and is added in specially selected 
		registries in the printer. The values from the whole day will be printed together with the daily financial 
		report.
	The command will not be successful if:
	-	No item has been programmed under the given number,
	-	No fiscal receipt has been opened,
	-	The maximum number of sales for one receipt (512) has already been registered.
	-	The command 35h has been successfully executed,
	-	The sum under one or more of the tax groups has turned out negative,
	-	The sum of surcharges and discounts within the receipt has remained negative,
	-	The journal is full</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_60_0_0.html">CMD_60_0_0</a></li></td>
					<td><pre>3CH (60)	CANCEL FISCAL RECEIPT
	
	Data field:	
		None
	Response:	
		None

	The command cancels an open fiscal receipt. All sales in the receipt are discarded. 
	The message "** CANCELLED **" is printed and then the receipt is closed as non-fiscal. 
	The command is not permitted, if command 53 (Total) is already executed for this receipt.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_61_0_0.html">CMD_61_0_0</a></li></td>
					<td><pre>3DH (61)	SETTING THE CLOCK - DATE AND HOUR

	Data field:
		TRGT_DATE	DD-MM-YY
		TRGT_TIME	HH:MM:SS
	Response:
		None

	You cannot set a date, which is earlier than the date of the last entry into the fiscal memory of device and the 
	capacity of this memory includes the year 2099. After RESET of memory, this command must be 
	executed - otherwise, the normal functioning of device cannot be resumed. 	The printer's real-time clock must 
	always be set correctly.
	Hardware limitations of the real time clock does not allow to set the seconds. After adjusting the clock seconds 
	counter will be 0!
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_62_0_0.html">CMD_62_0_0</a></li></td>
					<td><pre>3EH (62)	READING CURRENT DATE AND HOUR

	Data field:	
		None
	Response:	
		DD/MM/YY  HH:MM:SS
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_62_0_1.html">CMD_62_0_1</a></li></td>
					<td><pre>3EH (62)	READING CURRENT DATE AND HOUR

	Data field:	None
	Response:	
		DD	Day
		MM	Month
		YY	Year
		HH	Hour
		MM	Minute
		SS	Sec.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_63_0_0.html">CMD_63_0_0</a></li></td>
					<td><pre>3FH (63)	DISPLAYING THE DATE AND HOUR

	Data field:	None
	Response:	None

	Current date and time are displayed on lower line using the format: DD-MM-YYYY:HHMMSS.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_64_0_0.html">CMD_64_0_0</a></li></td>
					<td><pre>40H (64)	LAST FISCAL CLOSURE DETAILS

	Data field:	
		Option
	Response:	
		Closure
		TotA
		TotB
		TotC
		TotD
		TotE
		TotF
		ClosureDate

	Option		'0'- TotX	Tax group total.
			'1'- TotX	Tax group VAT
	Closure		Closure (Z-report) number
	ClosureDate	Closure date in format DDMMYY.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_65_0_0.html">CMD_65_0_0</a></li></td>
					<td><pre>41H (65)	DAILY TOTALS

	Data field:
		Option
	Response:	
		TotA
		TotB
		TotC
		TotD
		TotE
		TotF

	Option	'0'- TotX	Tax group total.
		'1'- TotX	Tax group VAT
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_68_0_0.html">CMD_68_0_0</a></li></td>
					<td><pre>44h (68)	THE NUMBER OF FREE FIELDS IN THE FISCAL MEMORY

	Data field:	None
	Response:	
		Logical
		Physical

	Logical		The number of logical locations for fiscal entries (4 bytes)
	Physical		Not used. Repeats the previous entry.

	The number of free fields in the fiscal memory, reserved for saving information from the daily report.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_69_0_0.html">CMD_69_0_0</a></li></td>
					<td><pre>45h (69)	DAILY FINANCIAL REPORT

	Data field:
		Option
		N
		A
	Response:
		Closure
		TotA
		TotB
		TotC
		TotD
		TotE
		TotF

	Option	A non-mandatory parameter controlling the type of generated report.
		'0'	A Z-report is printed. The printout ends with inscriptions "** NON-FISCAL **" if the 
			printer is not fiscalised.
		'2'	A X-report is generated, i.e., no entry into the fiscal memory is made and no closures are 
			performed. 
		The printout ends with inscription "** NON-FISCAL **". The same actions may be generated directly 
		from the printer using the menu.
	N	The presence of this symbol at the end of the data cancels the option to clear the data accumulated on 
		the operators during a Z-report.
	A	The presence of this symbol at the end of the data cancels the option to clear the data about sold article 
		quantities during a Z-report.
	
	Closure	Fiscal closure (Daily report) number - 4 bytes.
	TotX	The totals under all tax categories - A, B, C, D, E and F - 12 bytes with a sign.

	If the command is with Option '0', it will try to send report to FTP Server. It tries 15 minutes, if it is not able to 
	send, it will be printed, and the device will be functionally, but when next Z report must be printed, it will try to 
	send the last one, and it will not print the new one, while last was not sent.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_70_0_0.html">CMD_70_0_0</a></li></td>
					<td><pre>46h (70)	INTERNAL DEBITING AND CREDITING (serve In and Out)

	Data field:	
		InputSum
	Response:	
		ExitCode
		CashSum
		ServIn
		ServOut

	InputSum		The sum, which will be registered (up to 9 bytes). Depending on the sign of the digit, this 
			sum is interpreted either as credit or debit (ServeIn or ServeOut).

	ExitCode		One byte:
			'P'	The order has been completed. If the ordered sum is not 0, the printer will print 
				an interior receipt for registering the operation.
			'F'	The order has been cancelled. This happens if:
				-	The cash sum available is less than the ordered interior credit (ServeIn),
				-	There is an opened fiscal and non-fiscal receipt.

	CashSum		Available cash. Apart from this command, the sum grows after each payment in cash.
	ServIn		The sum from all commands "Interior credit"
	ServOut		The sum from all commands "Interior debit"

	Changes the content of the cash availability register. Depending on the sign of the sum in question, it is 
	accumulated in the register for interior debit-credit. The information is not saved in the fiscal memory of device 
	and is accessible until the performance of the daily closure. It is printed out at the command 69 (45h) and at the 
	generation of the daily report without closure from the printer itself. At successful completion of this 
	command, the drawer "kick-out" function is automatically activated.


</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_71_0_0.html">CMD_71_0_0</a></li></td>
					<td><pre>47h (71)	PRINTING DIAGNOSTIC INFORMATION

	Data field:	None
	Response:	None

	The command initiates the generation of an interior receipt containing diagnostic information as follows:
		-	Prints the date and version of the employed software,
		-	Prints the control sum of the employed firmware,
		-	Prints the serial port's band rate,
		-	Prints out the status of configuration keys and number of the country, the status 
			options being:

			Sw8 - Selects serial speed
			Sw7 - Selects serial speed
			Sw6 - Selects serial speed
			Sw5 - Not used
			Sw4 - Automatic paper cutting
			Sw3 - Half Cut
			Sw2 - Obligatory display
			Sw1 - Transparent display

			************************************
			Sw8	Sw7	Sw6	Speed
			************************************
			0	0	0	1200 bps
			0	0	1	2400 bps
			0	1	0	4800 bps
			0	1	1	9600 bps
			1	0	0	19200 bps
			1	0	1	38400 bps
			1	1	0	57600 bps
			1	1	1	115200 bps
			************************************

		-	Prints emergency time after power supply cut-off,
		-	Prints the number, date and hour of the last reset of the RAM (if there is such),
		-	Prints the current temperature of the two printer heads,
		-	Prints the overall number of fields in the fiscal memory and the number of the free fields,
		-	Prints the current date and hour.

	The command will not be executed when there is an open receipt in progress or when the paper roll has finished. 
	It may also be activated using the printer menu.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_72_0_0.html">CMD_72_0_0</a></li></td>
					<td><pre>48h (72)	FISCALIZATION

	Data field:	
		Serial
	Response:	
		ExitCode

	Serial	The serial number of device - it must be the number entered with command 5Bh. Status 5.3 is 
		used to verify whether the command has been successfully executed.
	
	ExitCode	Error code or 'P' symbol (when the action has been successful) is returned.

	The command will not be executed (and an error code will be set) if:
		'1'	The serial number is invalid,
		'2'	The printer has been fiscalized,
		'3'	No serial number has been programmed,
		'4'	The serial number is different from the one programmed,
		'5'	There is an opened receipt in progress,
		'6'	There are some already issued fiscal receipts or the 70 (46h) command has been executed after 
			the last daily report with closure,
		'7'	No tax rates have been entered into the memory of device,
		'8'	The tax registration number consists only of zeros,
		'9'	The clock needs setting.
	
	Fiscalization of device must be performed and after successful execution of the command, the returning of 
	printer to a "non-fiscalized" mode becomes impossible. The tax number is entered in the fiscal memory, together 
	with the current date and hour. The VAT rates are written to the fiscal memory, too. All registries are cleared 
	(to zero) after which the printer opens the first fiscal receipt, marks the moment of fiscalization on this 
	receipt and closes it.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_73_0_0.html">CMD_73_0_0</a></li></td>
					<td><pre>49H (73)	DETAILED FISCAL MEMORY REPORT BY CLOSURE NUMBER

	Data field:	
		Ext
		StartRec
		EndRec
	Response:	
		None

	Ext	Optional parameter - the letter 'X'. If present, additional information is printed in the report: 
		Fiscalisation date and time, tax rate changes date and time, reset date and time. Additionally every 
		tax rates change divides the report in separate blocks with grand totals. 
		This is non-standard reports, but contains additional useful information.
	StartRec	The number of the starting fiscal entry - 4 bytes
	EndRec	The number of the ending fiscal entry - 4 bytes

	The command leads to printing of a detailed report of the fiscal memory from one selected number to another.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_74_0_0.html">CMD_74_0_0</a></li></td>
					<td><pre>4Ah (74)	READING THE STATUS OPTIONS

	Data field:
		Option
	Response:	
		S0
		S1
		S2
		S3
		S4
		S5

	Option	One byte with the following meanings:
		'W'	All printer buffers must be printed out first.
		'X'	The status is returned immediately (default).
	Sn	Status byte n.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_74_0_1.html">CMD_74_0_1</a></li></td>
					<td><pre>4Ah (74)	READING THE STATUS OPTIONS

	Data field:	None
	Response:	
		S0
		S1
		S2
		S3
		S4
		S5

	Sn	Status byte n.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_76_0_0.html">CMD_76_0_0</a></li></td>
					<td><pre>4Ch (76)	STATUS OF THE FISCAL TRANSACTION

	Data field:	
		Option
	Repsonse:	
		FT_Opened
		Sales_Num
		Amount
		Tender

	Option		= 'T' If the parameter has been selected, the command will return the information on the 
			current state of the sum due for payment by client.

	FT_Opened	One byte, which is '1', if a fiscal or a non-fiscal receipt has been opened (which can be 
			understood from the status bytes) and '0' if there is no opened receipt.
	Sales_Num	The number of sales registered on the current or last fiscal receipt - 4 bytes.
	Amount		The sum from the last fiscal receipt - 9 bytes with a sign.
	Tender		The sum tendered against the current or the last receipt - 9 bytes with a sign (Only if Option 
			is present).
	
	The command supports the PC application's ability to monitor the status and, if needed, to restore and complete 
	an already started fiscal operation, which has been interrupted on emergency or out of time - for example, as a 
	result of a power failure.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_79_0_0.html">CMD_79_0_0</a></li></td>
					<td><pre>4Fh (79)	SHORT FISCAL MEMORY REPORT BY CLOSURE DATE

	Data field:	 
		Ext 
		StartDate 
		EndDate 
	Response:	
		None

	Ext	Optional parameter - the letter 'X'. If present, additional information is printed in the 
		report: Fiscalisation date and time, tax rate changes 
		date and time, reset date and time. Additionally every tax rates change divides the report 
		in separate blocks with grand totals. 
		This is non-standard reports, but contains additional useful information.

	StartDate       Starting date - 6 bytes (DDMMYY)
	EndDate         End date - 6 bytes (DDMMYY)

	The command generates printing out of a short periodic financial report.
	If the second parameter is not present, then the command generates a short monthly or annual report. The syntax 
	in this case is:
	
	StartMonth - 4 bytes (MMYY) for monthly report.
	StartYear - 2 bytes (YY) for annual report.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_80_0_0.html">CMD_80_0_0</a></li></td>
					<td><pre>50h (80)	SOUND SIGNAL

	Data field:	
		SoundData
	Response:	
		None

	This command is used for making (beeping) a sequence of sounds with a certain frequency and duration. 
	The data is in format, similar to the one used for writing notes and can be of any length up to 218 bytes. 
	The first invalid character cancels the command. If the input string is empty, the one sound signal with 
	frequency 2 kHz and duration 300 ms is emitted. 

	SoundData format is a sequence of the following sub-commands:

	-	Notes of the scale: One latine letter with value from 'A' to 'G'.
			'C' - Do
			'D' - Re
			'E' - Mi
			'F' - Fa
			'G' - Sol
			'A' - La
			'B' - Si
		If immediately after the note comes character '#', then the note is higher in pitch by a semitone (sharp). 
		If immediately after the note comes character '&', then the note is lower in pitch by a semitone (flat). 

	-	Pause: Character space (ASCII 20h).
		After a note or pause there can be one or a few bytes, which specify the duration. Valid are characters 
		from '0' to '5', they have the following meaning:
			'0'	basic duration of a note/pause
			'1'	basic duration * 2
			'2'	basic duration * 4
			'3'	basic duration * 8
			'4'	basic duration * 16
			'5'	basic duration * 32
		If there are a few durations one after another they are summed up. 

	-	Going to higher scale: character '+'.
	-	Going to lower scale: character '-'.
	-	Specifying tempo: character '^', followed by a number. The number specifies the percentage: duration 
		of notes and intervals to basic duration. 
		Values:
			'1'	200 %
			'2'	175 %
			'3'	140 %
			'4'	120 %
			'5'	100 %
			'6'	80 %
			'7'	60 %
			'8'	50 %
			'9'	40 %

	-	Return to scale 1 (it is default). Character '@'. Tone 'La' in it is 440 Hz.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_83_0_0.html">CMD_83_0_0</a></li></td>
					<td><pre>53h (83)	SETTING THE MULTIPLIER, DECIMALS AND DISABLED TAXES

	Data fields:	
		Multiplier
		Decimals
		EnabledSwitches
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF
	Response:		
		Multiplier
		Decimals
		Enabled
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF

	Multiplier		
			A multiplier between 0 and 3 which shows the degree of 10 before multiplying it times the 
			input or output value (at present deactivated and out of use).

	Decimals		
			One byte with a value 0 or 2 and shows the exact place of the decimal point.

	EnabledSwitches	
			6 bytes with value '0' or '1', corresponding to VAT groups 'A', 'B', 'C', 'D', 'E', 'F'. '0' means 
			disabled VAT group, '1' - enabled VAT group. 
			VAT group 'F' has to be always enabled!

	TaxX		
			The VAT rate for the corresponding VAT group in % with up to 2 decimals (0.00 to 99.00). 
			VAT group 'F' has to be always 0.00!
	
	If nothing is entered in the data field, the FP returns the currently valid values. Even when only one of the parameters 
	must be changed, the rest must be entered too. The fiscal memory has a fixed capacity for a set number of entries, 
	and for that reason the command can be performed not more than 19 times after the fiscalisation. 
	Before the fiscalisation the data are hold in RAM only and may be changed without limitations. 
	The fiscalisation command (72) makes the first such record.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_83_0_1.html">CMD_83_0_1</a></li></td>
					<td><pre>53h (83)	SETTING THE MULTIPLIER, DECIMALS AND DISABLED TAXES

	Data fields:	
		None
	Response:	
		Multiplier
		Decimals
		Enabled
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF

	Multiplier		
			A multiplier between 0 and 3 which shows the degree of 10 before multiplying it times the 
			input or output value (at present deactivated and out of use).

	Decimals		
			One byte with a value 0 or 2 and shows the exact place of the decimal point.

	EnabledSwitches	
			6 bytes with value '0' or '1', corresponding to VAT groups 'A', 'B', 'C', 'D', 'E', 'F'. '0' means 
			disabled VAT group, '1' - enabled VAT group. VAT group 'F' has to be always enabled!
	TaxX		
			The VAT rate for the corresponding VAT group in % with up to 2 decimals (0.00 to 99.00). 
			VAT group 'F' has to be always 0.00!
	
	If nothing is entered in the data field, the FP returns the currently valid values. Even when only one of the 
	parameters must be changed, the rest must be entered too. The fiscal memory has a fixed capacity for a set 
	number of entries, and for that reason the command can be performed not more than 19 times after the fiscalisation. 
	Before the fiscalisation the data are hold in RAM only and may be changed without limitations. The fiscalisation 
	command (72) makes the first such record.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_84_0_0.html">CMD_84_0_0</a></li></td>
					<td><pre>54h (84)	PRINTING A BAR CODE
	
	Data field:	
		BC_Type
		Data
	Response:	
		None

	BC_Type	Bar code type. 1 byte with possible value:
		'1'	EAN8 bar code. Data contains only digits and is 7 bytes long. The check sum is 
			automatically calculated and printed.
		'2'	EAN13 bar code. Data contains only digits and is 12 bytes long. The check sum 
			is automatically calculated and printed.
		'3'	Code128 bar code. Data contains symbols with ASCII codes between 32 and 127. 
			Data length is between 16 and 32 symbols 
			(depends on the content - the maximum length is if all symbol are digits). The 
			check sum is automatically calculated and printed.
		'4'	Interleaved 2 of 5 bar code. Data contains only digits and is up to 28 bytes long. 
			No check 	sum is calculated and printed.
		'5'	Interleaved 2 of 5 bar code. Data contains only digits and is up to 27 bytes long. 
			The check sum is automatically calculated and printed.

	The command prints a bar code. 
	Printing a bar code is permitted only in an opened fiscal or non-fiscal receipt. The bar code is centered. 
	If data length or content is not valid, nothing is printed and "Syntax error" status bit is set.
	Below the bar code human readable text of the bar code data is printed.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_84_0_1.html">CMD_84_0_1</a></li></td>
					<td><pre>54h (84)	PRINTING A BAR CODE
	
	Data field:
		BC_Type
		Data
	Response:	
		None

	BC_Type	Bar code type. 1 byte with possible value:
		'1'	EAN8 bar code. Data contains only digits and is 7 bytes long. The check sum is 
			automatically calculated and printed.
		'2'	EAN13 bar code. Data contains only digits and is 12 bytes long. The check sum is 
			automatically calculated and printed.
		'3'	Code128 bar code. Data contains symbols with ASCII codes between 32 and 127. 
			Data length is between 16 and 32 symbols 
			(depends on the content - the maximum length is if all symbol are digits). The 
			check sum is automatically calculated and printed.
		'4'	Interleaved 2 of 5 bar code. Data contains only digits and is up to 28 bytes long.
			No check	sum is calculated and printed.
		'5'	Interleaved 2 of 5 bar code. Data contains only digits and is up to 27 bytes long. 
			The check sum is automatically calculated and printed.

	The command prints a bar code. 
	Printing a bar code is permitted only in an opened fiscal or non-fiscal receipt. The bar code is centered. 
	If data length or content is not valid, nothing is printed and "Syntax error" status bit is set.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_85_0_0.html">CMD_85_0_0</a></li></td>
					<td><pre>55H (85)	DEFINE ADDITIONAL PAYMENT TYPES NAME

	Data field: 
		Option
		INPUT_NAME
	Response:	
		FP_Result
		OUTPUT_NAME

	Option:
		'I'	Additional payment 1
		'J'	Additional payment 2
		'K'	Additional payment 3
		'L'	Additional payment 4

	INPUT_NAME	Comment text of the payment. Up to 24 bytes. If not present, the current name 
			is returned.

	Result	One byte:
		'P'	No error.
		'F'	INPUT_NAME longer than 24 bytes.
	OUTPUT_NAME	Comment text) of the payment. Up to 24 bytes.

	The command defines the comment text, printed before the additional (programmable) payments. 
	The command is not permitted after the first fiscal receipt for the day.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_85_0_1.html">CMD_85_0_1</a></li></td>
					<td><pre>55H (85)	DEFINE ADDITIONAL PAYMENT TYPES NAME

	Data field: 
		Option
	Response:	 
		FP_Result|OUTPUT_NAME

	Option:
		'I'	Additional payment 1
		'J'	Additional payment 2
		'K'	Additional payment 3
		'L'	Additional payment 4
		

	Result	One byte:
		'P'	No error.
		'F'	INPUT_NAME longer than 24 bytes.
	OUTPUT_NAME	Comment text) of the payment. Up to 24 bytes.

	The current name is returned.
	The command is not permitted after the first fiscal receipt for the day.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_86_0_0.html">CMD_86_0_0</a></li></td>
					<td><pre>56H (86)	GET LATEST FISCAL MEMORY RECORD DATE

	Data field: 
		None
	Response:	 
		LFMR_DT

	LFMR_DT	
		Date and time of last (latest) record in the fiscal memory in format DD-MM-YYYY hh:mm:ss</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_86_0_1.html">CMD_86_0_1</a></li></td>
					<td><pre>56H (86)	GET LATEST FISCAL MEMORY RECORD DATE

	Data field: 
		None
	Response:	 
		DD
		MM
		YYYY
		HH
		MMM
		SS

	Date and time of last (latest) record in the fiscal memory:

	DD - Day
	MM - Month
	YYYY - Year
	HH - Hours
	MMM - Minutes
	SS - Sec.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_90_0_0.html">CMD_90_0_0</a></li></td>
					<td><pre>5Ah (90)	RETURNS DIAGONSTIC INFORMATION

	Data field:	
		None
	Response:	
		PrinterName
		FwRev_FwDate
		Chk
		ConfigSwitches
		SerialNumber

	PrinterName	
		Name of the printer (the string "FP2000").

	FwRev_FwDate	
		The version of the software program (4 bytes)+[Space(1 byte)]+The date of the firmware 
		program DDMmmYY(7 bytes).
	Chk	
		The EPROM control sum - a 4 bytes string in the hexadecimal code. 
		For example, if the control sum is 214Ah, it will be presented as 32h, 31h, 34h, 42h

	ConfigSwitches	
		The configuration switches from Sw1 to Sw8 - a 8 bytes string with '0' or '1'.

	Serial		
		The serial number - 10 bytes.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_91_0_0.html">CMD_91_0_0</a></li></td>
					<td><pre>5Bh (91)	PROGRAMMING THE SERIAL

	Data field:	
		Serial
	Response:		
		FP_Result
		CountryStr

	Serial
		The serial number. 10 symbols - 2 digits, 2 letters and 6 digits in this order.
	
	FP_Result		
		One byte.  
		'P' - OK; 
		'F' - errors.

	CountryStr	
		The name of country. 
		For example: "TANZANIA"
	
	The serial number is entered and written to the fiscal memory. It cannot be changed anymore. 
	The printer must be turned off to recognize a new EJ Card.
	If Result = 'F' and the S1.1 flag is raised, the command has not been successful because either the 
	fiscal memory has not been formatted or the serial number has already been entered.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_92_0_0.html">CMD_92_0_0</a></li></td>
					<td><pre>5Ch (92)	PRINT SEPARATOR LINE

Data field:
	LineType
Response:	
	None

	LineType	The type of the separator line. One byte with possible value:
		'1'	The line is filled with the symbol '-'.
		'2'	The line is filled with the symbols '-' and ' ' (space).
		'3'	The line is filled with the symbols '='.

The command prints a separator line using the full width of the paper (36 symbols). It is permitted in an open 
fiscal, non-fiscal or refund receipt only</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_93_0_0.html">CMD_93_0_0</a></li></td>
					<td><pre>5Dh (93)	GET DISCOUNTS AND MARKUPS

	Data field:	
		None
	Response:	
		DiscountsCnt
		DiscountsSum
		MarkupsCnt
		MarkupsSum


	DiscountsCnt	
		Number of Discounts.

	DiscountsSum	
		Sum of Discounts.

	MarkupsCnt	
		Number of Markups.

	MarkupsSum	
		Sum of Markups.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_94_0_0.html">CMD_94_0_0</a></li></td>
					<td><pre>5Eh (94)	DETAILED FISCAL MEMORY REPORT BY CLOSURE DATE

	Data field:	
		Ext 
		StartDate
		EndDate
	Response:	
		None

	Ext	
		Optional parameter - the letter 'X'. If present, additional information is printed in the report: 
		Fiscalisation date and time, tax rate changes date and time, reset date and time. Additionally 
		every tax rates change divides the report in separate blocks with grand totals. 
		This is non-standard reports, but contains additional useful information.

	StartDate	
		Starting date of selected fiscal entry - 6 bytes (DDMMYY)

	EndDate	
		End date of the fiscal entry - 6 bytes (DDMMYY)

	This command prints out a detailed financial report of the period between two selected dates.
	If the second parameter is not present, then the command generates a short monthly or annual report. 
	The syntax in this case is:

	StartDate	
		Month - 4 bytes (MMYY) for monthly report.

	StartDate	
		Year - 2 bytes (YY) for annual report.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_95_0_0.html">CMD_95_0_0</a></li></td>
					<td><pre>5Fh (95)	SHORT FISCAL MEMORY REPORT BY CLOSURE NUMBER

	Data field:	
		Ext
		StartNumber
		EndNumber
	Response:	
		None

	Ext		
		Optional parameter - the letter 'X'. If present, additional information is printed in the report: 
		Fiscalisation date and time, tax rate changes date and time, reset date and time. Additionally 
		every tax rates change divides the report in separate blocks with grand totals. 
		This is non-standard reports, but contains additional useful information.

	StartNumber
		Starting number of fiscal entry

	EndNumber	
		End number of fiscal entry</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_97_0_0.html">CMD_97_0_0</a></li></td>
					<td><pre>61h (97)	READING THE SETTED TAX RATES

	Data field:	
		None
	Response:	
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF

	TaxA	Current tax rate A
	TaxB	Current tax rate B
	TaxC	Current tax rate C
	TaxD	Current tax rate D
	TaxE	Current tax rate E
	TaxF	Current tax rate F</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_98_0_0.html">CMD_98_0_0</a></li></td>
					<td><pre>62h (98)	SETTING THE TAX REGISTRATION NUMBER

	Data field:	
		TIN
		VRN
	Response:	
		None

	TIN	The TAX identification number as a text (9 bytes).
	VRN	The VAT identification number as a text (9 bytes).</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_99_0_0.html">CMD_99_0_0</a></li></td>
					<td><pre>63h (99)	Reading the TAX REGISTRATION NUMBER

	Data field:	
		None
	Response:	
		TIN
		VRN

	TIN	The TAX identification number as a text (9 bytes).
	VRN	The VAT identification number as a text (9 bytes).</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_89_0_0.html">CMD_89_0_0</a></li></td>
					<td><pre>59h (89)	PROGRAMMING THE PRODUCTION TEST AREA

	Data field:	
		None
	Response:	
		Result
		Free

	Entry into the fiscal memory is done.

	FP_Result	
		'P'	No error
		'F'	Error

	FreeRecords
		The number of the free blocks left for saving such entries - 4 bytes.

The command is executed for testing the fiscal memory.
Test block for entries into the fiscal memory: 55h,AAh,33h,CCh,5Ah, A5h,3Ch,C3h
If - and when - the S1.1 flag has been raised, the fiscal memory has not been formatted or is in 
the READONLY mode.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_89_0_1.html">CMD_89_0_1</a></li></td>
					<td><pre>59h (89)	PROGRAMMING THE PRODUCTION TEST AREA

	Data field:	
		None
	Response:	
		Result
		Free

	There will be no 'save' performed and only the parameters will be returned.

	FP_Result	
		'P'	No error
		'F'	Error

	FreeRecords
		The number of the free blocks left for saving such entries - 4 bytes.

The command is executed for testing the fiscal memory.
Test block for entries into the fiscal memory: 55h,AAh,33h,CCh,5Ah, A5h,3Ch,C3h
If - and when - the S1.1 flag has been raised, the fiscal memory has not been formatted or is in 
the READONLY mode.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_100_0_0.html">CMD_100_0_0</a></li></td>
					<td><pre>64h (100)	SHOWING TEXT ON DISPLAY

	Data field:	
		INPUT_TEXT
	Response:	
		None

	INPUT_TEXT	
		A text of no more than 40 symbols sent for displaying. If symbols with ASCII codes 
		smaller than 20h (control symbols), they are increased with 40h and are preceded by 10h.
		Example: To send 1Bh, 4Bh, 00h the data field will have to contain 10h, 5Bh, 10h, 40h.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_101_0_0.html">CMD_101_0_0</a></li></td>
					<td><pre>65h (101)	SETTING THE OPERATOR'S PASSWORD

	Data field:	
		OpCode
		OldPwd
		NewPwd
	Response:	
		None

	OpCode	
		Operator's code (1 to 16)

	OldPwd	
		Old password (4 to 8 digits)

	NewPwd	
		New password (4 to 8 digits)

Sets one of the 16 operator's passwords, which will be demanded upon opening a fiscal receipt. After three 
erroneous password entries, the printer will block, it must then be switched OFF and ON again to continue 
operating.
After initialization or reset of the operational memory, all 16 passwords are "0000".</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_102_0_0.html">CMD_102_0_0</a></li></td>
					<td><pre>66h (102)	ENTERING OPERATOR'S NAME

	Data field:	
		OpCode
		Pwd
		OpName
	Response:	
		None

	OpCode	
		Operator's code (1 to 16)

	Pwd	
		Password (4 to 6 digits)

	OpName	
		Name of the operator (up to 24 symbols)

Enters one of the 16 operator names. The number and name of the operator are printed at the beginning of each 
fiscal (clients) receipt. 
After three erroneous password entries, the printer will block, it must then be switched OFF and ON again 
to continue operating. After initialization or reset of the operational memory, all 16 password locations are empty.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_103_0_0.html">CMD_103_0_0</a></li></td>
					<td><pre>67h (103)	INFORMATION ON THE CURRENT RECEIPT

	Data field:	
		None
	Response:	
		CanVd
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF

	CanVd	Possible/impossible return (sale registration with a negative sign) ['0' / '1']
	TaxA	The sum accumulated under tax A
	TaxB	The sum accumulated under tax B
	TaxC	The sum accumulated under tax C
	TaxD	The sum accumulated under tax D
	TaxE	The sum accumulated under tax E
	TaxF	The sum accumulated under tax F

The command offers information on sums accumulated so far under the different tax groups and whether it is 
possible to return the registered items sold.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_105_0_0.html">CMD_105_0_0</a></li></td>
					<td><pre>68h (105)	OPERATOR'S REPORT

	Data field:	None
	Response:	None

Information on the sales, performed by the operators, is printed out where for each separate operator the 
following data is printed out: name, individual number, number of fiscal receipts, discharges made, surcharge, 
sum adjustments and accumulated total sums.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_106_0_0.html">CMD_106_0_0</a></li></td>
					<td><pre>6Ah (106)	DRAWER KICK OUT

	Data field:	
		mSec
	Response:	
		None

	mSec	The length of the impulse in milliseconds (5-100)
	
Sends an impulse for opening the cash drawer. This parameter sets a new value for the length of the impulse, which 
is stored in the memory of the printer. 
If this parameter is skipped, the last entered value remains valid. After memory RESET, a value of 15 ms is set.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_0_0.html">CMD_107_0_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS

	Articles information

	Data field:		
		None
	Response:		
		ErrorCode
		Total
		Prog
		Len

	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command

	Total		Total programmable article count (3000 for this printer).
	Progr		Programmed article count.
	Len		Maximal article name length (36 for this printer).</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_1_0.html">CMD_107_1_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS

Programming an item

Up to 3000 different items may be programmed and the command will be rejected if a similar item has already 
been programmed in the memory of printer and sales of this item have been registered. An item with zero 
accumulated sums is subject to change. The number of the free items is returned after an ErrorCode parameter.

	Data field:	
		TaxGr
		PLU
		Group
		SPrice
		Replace
		Quantity
		ItemName
	Response:	
		ErrorCode,FreeItemsNumber


	TaxGr	
		Tax group. One byte ('A', 'B', 'C', 'D', 'E' or 'F').
	PLU	
		Number of the item (1 to 999999999)
	Group	
		Article group (1 - 99).
	SPrice	
		Singular price - up to 8 meaningful digits.
	Replace	
		One byte with value 'A'. Changes the meaning of the next parameter (Quantity).
	Quantity	
		A number with up to 3 decimals - the available quantity of the article. If Replace is 
		present, then the available quantity is replaced with this parameter, otherwise it is added 
		to the old value (if the article is already programmed, of course). Every sale command of 
		this article will decrease this value.
	ItemName	
		Name of the item - up to 36 bytes.


	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command
	FreeItemsNumber	
		The number of the free items is returned after an ErrorCode parameter.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_2_0.html">CMD_107_2_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS

Change the quantity of an item
Changing the quantity is possible, if the article is programmed.

	Data field:	
		PLU
		Quantity
	Response:	
		ErrorCode

	PLU
		Article number (1 to 999999999).
	Quantity	
		Quantity correction - a floating-point number with 3 decimal places. Positive number 
		increases the available quantity, negative decreases it.


	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
		'P'	Successful command
		'F'	Unsuccessful command


</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_3_0.html">CMD_107_3_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS

Change the price of an item
Changing the price if possible, if the article is programmed and no sales of this article are made in the 
fiscal receipt (if a fiscal receipt is open).

	Data field:	
		PLU
		Sprice
	Response:	
		ErrorCode


	PLU	Article number (1 to 999999999).
	SPrice	Singular price - up to 8 meaningful digits.



	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
		'P'	Successful command
		'F'	Unsuccessful command


</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_4_0.html">CMD_107_4_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS

	Delete all items with non-zero accumulated sums.

	Data field:	
		None
	Response:	
		ErrorCode


	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
		'P'	Successful command
		'F'	Unsuccessful command

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_4_1.html">CMD_107_4_1</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS

	Delete all items with non-zero accumulated sums.

	Data field:	
		PLU
	Response:	
		ErrorCode

	PLU
		Deletes article with selected number if there are no accumulated sums.

	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
		'P'	Successful command
		'F'	Unsuccessful command</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_4_2.html">CMD_107_4_2</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS

	Delete all items with non-zero accumulated sums.

	Data field:	
		PLU1
		PLU2
	Response:	
		ErrorCode

	PLU1
	PLU2	
		Deletes the articles within a set interval which do not have accumulated sums.

	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
		'P'	Successful command
		'F'	Unsuccessful command</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_5_0.html">CMD_107_5_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS


	Reading Item data

	Data field:	
		PLU
	Response:	
		ErrorCode
		PLU
		TaxGr
		Group
		SPrice
		Total
		Sold
		Available
		ItemName


	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command	

	PLU	
		Individual number of the item. 9 digits (000000001 to 999999999)
	TaxGr	
		Tax group - 1 byte
	Group	
		Article group. 2 digits (01 - 99).
	SPrice	
		Singular price. A floating-point number - decimal places depend on the count set 
		using command 83 (53h).
	Total	Accumulated sum for this article.
	Sold	Accumulated quantity - a floating-point number with 3 decimal places.
	Available	Available quantity of this article.
	ItemName	The name of the item. Up to 36 symbols.
	
If the item cannot be found, one 'F' byte is returned.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_6_0.html">CMD_107_6_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS


	Returning the data on the first found programmed item. 
	ANSWER_PLU is the first programmed article with number greater than or equal to PLU.

	Data field:	
		PLU
	Response:
		ErrorCode
		PLU
		TaxGr
		Group
		SPrice
		Total
		Sold
		Available
		ItemName


	ErrorCode
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command	

	ANSWER_PLU	
		Individual number of the item. 9 digits (000000001 to 999999999)

	TaxGr
		Tax group - 1 byte

	Group
		Article group. 2 digits (01 - 99).
	SPrice
		Singular price. A floating-point number - decimal places depend on the count set 
		using command 83 (53h).
	Total
		Accumulated sum for this article.
	Sold
		Accumulated quantity - a floating-point number with 3 decimal places.
	Available
		Available quantity of this article.
	ItemName
		The name of the item. Up to 36 symbols.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_7_0.html">CMD_107_7_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS


	Returning the data on the programmed item with the greatest number.
	ANSWER_PLU is the first programmed article with number lower than or equal to PLU is 
	returned. 

	Data field:	
		PLU
	Response:	
		ErrorCode
		PLU
		TaxGr
		Group
		SPrice
		Total
		Sold
		Available
		ItemName


	ErrorCode
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command	



	ANSWER_PLU
			Individual number of the item. 9 digits (000000001 to 999999999)

	TaxGr		
			Tax group - 1 byte

	Group		
			Article group. 2 digits (01 - 99).

	SPrice		
		Singular price. A floating-point number - decimal places depend on the count set
		using command 83 (53h).

	Total		
		Accumulated sum for this article.

	Sold	
		Accumulated quantity - a floating-point number with 3 decimal places.

	Available	
		Available quantity of this article.

	ItemName	
		The name of the item. Up to 36 symbols.

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_8_0.html">CMD_107_8_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS


Returning the data on the next found programmed item.
Depending of the starting subcommand ('First (CMD_107_6_0)' or 'Last (CMD_107_7_0)'), the articles 
are enumerated in ascending or descending order.

	Data field:
		PLU
	Response:	
		ErrorCode
		PLU
		TaxGr
		Group
		SPrice
		Total
		Sold
		Available
		ItemName


	ErrorCode
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command	

	ANSWER_PLU	
		Individual number of the item. 9 digits (000000001 to 999999999)

	TaxGr
		Tax group - 1 byte

	Group
		Article group. 2 digits (01 - 99).

	SPrice
		Singular price. A floating-point number - decimal places depend on the count set 
		using command 83 (53h).

	Total
		Accumulated sum for this article.

	Sold
		Accumulated quantity - a floating-point number with 3 decimal places.

	Available
		Available quantity of this article.

	ItemName
		The name of the item. Up to 36 symbols.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_9_0.html">CMD_107_9_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS


	Returning the data on the first sold item.
	ANSWER_PLU is the first sold article with number greater than or equal to PLU is returned. 

	Data field:	
		PLU
	Response:	
		ErrorCode
		PLU
		TaxGr
		Group
		SPrice
		Total
		Sold
		Available
		ItemName


	ErrorCode
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command	

	ANSWER_PLU
		Individual number of the item. 9 digits (000000001 to 999999999)

	TaxGr
		Tax group - 1 byte

	Group
		Article group. 2 digits (01 - 99).

	SPrice
		Singular price. A floating-point number - decimal places depend on the count set 
		using command 83 (53h).

	Total
		Accumulated sum for this article.
	Sold
		Accumulated quantity - a floating-point number with 3 decimal places.

	Available
		Available quantity of this article.

	ItemName	
		The name of the item. Up to 36 symbols.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_10_0.html">CMD_107_10_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS


Returning the data on the sold item with the greatest number.
ANSWER_PLU is the first sold article with number lower than or equal to PLU is returned.

	Data field:	
		PLU
	Response:	
		ErrorCode
		PLU
		TaxGr
		Group
		SPrice
		Total
		Sold
		Available
		ItemName


	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command	

	ANSWER_PLU	
		Individual number of the item. 9 digits (000000001 to 999999999)

	TaxGr
		Tax group - 1 byte

	Group
		Article group. 2 digits (01 - 99).

	SPrice
		Singular price. A floating-point number - decimal places depend on the count set 
		using command 83 (53h).

	Total
		Accumulated sum for this article.

	Sold
		Accumulated quantity - a floating-point number with 3 decimal places.

	Available
		Available quantity of this article.

	ItemName	
		The name of the item. Up to 36 symbols.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_11_0.html">CMD_107_11_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS


Returning the data on the next found sold item.
Depending of the starting subcommand ('First (CMD_107_9_0)' or 'Last (CMD_107_10_0)'), the 
articles are enumerated in ascending or descending order.

	Data field:	
		PLU
	Response:	
		ErrorCode
		PLU
		TaxGr
		Group
		SPrice
		Total
		Sold
		Available
		ItemName


	ErrorCode
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command	
	ANSWER_PLU
		Individual number of the item. 9 digits (000000001 to 999999999)

	TaxGr	
		Tax group - 1 byte

	Group
		Article group. 2 digits (01 - 99).

	SPrice
		Singular price. A floating-point number - decimal places depend on the count set 
		using command 83 (53h).

	Total
		Accumulated sum for this article.

	Sold
		Accumulated quantity - a floating-point number with 3 decimal places.

	Available
		Available quantity of this article.

	ItemName	
		The name of the item. Up to 36 symbols.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_12_0.html">CMD_107_12_0</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS


Returning the data on the first free item.
ANSWER_PLU is the first free (not programmed) article with number greater than or equal to PLU is 
returned.

	Data field:	
		PLU
	Response:	
		ErrorCode
		ANSWER_PLU


	ErrorCode	
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command	
	ANSWER_PLU	
		Individual number of the item. 9 digits (000000001 to 999999999)</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_107_12_1.html">CMD_107_12_1</a></li></td>
					<td><pre>6Bh (107)	DEFINING AND READING ITEMS


Returning the data on the last free item.
ANSWER_PLU is the first free (not programmed) article with number lower than or equal to PLU is 
returned.

	Data field:	
		PLU
	Response:	
		ErrorCode
		ANSWER_PLU


	ErrorCode
		One byte, showing the result from the operation and having the following meaning:
			'P'	Successful command
			'F'	Unsuccessful command	
	ANSWER_PLU
		Individual number of the item. 9 digits (000000001 to 999999999)</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_109_0.html">CMD_109_0</a></li></td>
					<td><pre>Dh (109)	PRINTING A DUPLICATE RECEIPT

	Data field:	
		Count
	Response:	
		None

	Count	Number of duplicate receipts (only a value of 1 is accepted).


The command initiates the printing of a copy of the last closed receipt containing registered sales. 
The copy is marked as an "** NON-FISCAL **". Immediately after tax registration number, the 
inscription "DUPLICATE" is printed out in bold letters.
The printer will refuse to print a second copy of a receipt.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_110_0.html">CMD_110_0</a></li></td>
					<td><pre>6Eh (110)	PAYMENT INFORMATION

	Data field:	
		None
	Response:	
		Cash
		Credit
		Debit
		Cheque
		Pay1
		Pay2
		Pay3
		Pay4
		Closure
		Receipt

	Cash	Paid in cash
	Credit	Payment credited
	Debit	Paid with a debit card
	Cheque	Paid with a cheque
	PayX	Payd with one of the additional payment types ('I', 'J', 'K', 'L').
	Closure	Current (last) fiscal entry
	Receipt	Number of the next fiscal receipt
	
Returns information on distribution of the daily sum according to terms of payment used.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_111_0.html">CMD_111_0</a></li></td>
					<td><pre>6Fh (111)	ITEMS REPORT

	Data field:	
		Option
		Start
		End
	Reponse:	
		ErrorCode

	Option	
		Defines the type of information under print. Possible values:
		- 'S'	Only sold items are printed out. The data on these items include: 
			the individual number, VAT group, group, name, 
			single price, sold quantity and total sum for the day.
		- 'P'	All programmed items are printed out, containing their number, 
			VAT group, group, name, sold quantity, available quantity and 
			single price.

	START_PLU
		First article number (PLU) printed. PLUs less than this are not included in 
		the report. Default: 1.
	END_PLU
		Last article number (PLU) printed. PLUs greater than this are not included 
		in the report. Default: 999999999.

	ErrorCode
		One byte, showing the result from the operation and having the following 
		meaning:
			'P'	Successful command
			'F'	Unsuccessful command
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_111_1.html">CMD_111_1</a></li></td>
					<td><pre>6Fh (111)	ITEMS REPORT

	Data field:	
		Option
		Group
	Reponse:	
		ErrorCode

	Option	
		Defines the type of information under print. Possible values:
		- 'S'	Only sold items are printed out. The data on these items include: 
			the individual number, VAT group, group, name, single price, 
			sold quantity and total sum for the day.
		- 'P'	All programmed items are printed out, containing their number, 
			VAT group, group, name, sold quantity, available quantity and 
			single price.

	Group
		A number from 1 to 99. If present, only articles from this group 
		are printed, otherwise all articles are printed.

	ErrorCode
		One byte, showing the result from the operation and having the following 
		meaning:
			'P'	Successful command
			'F'	Unsuccessful command</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_112_0.html">CMD_112_0</a></li></td>
					<td><pre>70h (112)	READING INFORMATION ON THE OPERATOR

Data field:	
	OperatorNumber
Response:		

	OperatorNumber	
			Number of the operator (1 to 16)

	ReceiptsNumber
			Number of fiscal receipts, issued by the operator

	RegisteredSalesNumber
			Number of registered sales

	TotalAccumulatedSum
			Total accumulated sum

	DiscountsNumber
			Number of discounts

	TotalDiscountsNumber
			Total number of discounts

	MarkUpNumber	
			Number of mark ups

	TotalMarkUpNumber
			Total number of mark ups made

	VoidNumber
			Number of voids (and corrections of sums)

	VoidsTotal
			Total sum of voids (and corrections of sums)

	OperatorName
			Name of the operator

	OperatorPassword			
			Operators password. Present only the printer is in service mode.

The command leads to the reading of the available information, which will be printed out in the 
operator's report. The sums are returned as floating-point numbers incorporating the currently 
set number of decimal places.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_113_0.html">CMD_113_0</a></li></td>
					<td><pre>71h (113)	READING THE NUMBER OF THE LAST PRINTED DOCUMENT

	Data field:	
		None
	Response:	
		Fiscal
		NonFiscal
		Document

	Fiscal	
		The number of the last issued fiscal receipt (8 digits)

	NonFiscal	
		The number of the last issued non-fiscal receipt (8 digits)

	Document	
		The number of the last issued document (8 digits)</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_0.html">CMD_114_0</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about active decimals and VAT rates for the Z-report record.

	Data field:	
		Closure1
	Response:	
		ErrorCode
		DecRec
		DecimalsCount
		VATEnabled
		PercA
		PercB
		PercC
		PercD
		PercE
		PercF
		DT

	Closure1	
		Number of the fiscal memory record.

	ErrorCode	
		One byte with a value of:
			- 'P'	The data are valid.
			- 'F'	Wrong control sum in the entry. No data available.
			- 'E'	The selected entry is empty. No data available.
	
	
	DecRec		Last (active) decimals and VAT rates record number.
	DecimalsCount	Decimals count for this Z-report record.
	VATEnabled	Enabled VAT rates mask - 4 bytes with values '0' or '1', where 
			'1' means "enabled".
	PercA		VAT rate for the corresponding VAT group in percents.
	PercB		VAT rate for the corresponding VAT group in percents.
	PercC		VAT rate for the corresponding VAT group in percents.
	PercD		VAT rate for the corresponding VAT group in percents.
	PercE		VAT rate for the corresponding VAT group in percents.
	PercF		VAT rate for the corresponding VAT group in percents.
	DT		Date and time of the data in format: DD-MM-YY hh:mm:ss.
	

The command returns information on different tax groups for each separate entry 
and or a selected period of time. 
Periodic references for longer time periods may take few seconds to process.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_1.html">CMD_114_1</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about total (turnover) sums for the Z-report record.

	Data field:	
		Closure1
	Response:		
		ErrorCode
		Clos
		Fisc
		TotA
		TotB
		TotC
		TotD
		TotE
		TotF

	Closure1		
		Number of the fiscal memory record.

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	Clos	Z-report record number.
	Fisc	Fiscal receipts count.
	TotA	Total (turnover) sum for the corresponding VAT group.
	TotB	Total (turnover) sum for the corresponding VAT group.
	TotC	Total (turnover) sum for the corresponding VAT group.
	TotD	Total (turnover) sum for the corresponding VAT group.
	TotE	Total (turnover) sum for the corresponding VAT group.
	TotF	Total (turnover) sum for the corresponding VAT group.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_2.html">CMD_114_2</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about total (turnover) sums for the Z-report record.

	Data field:	
		Closure1
		Closure2
	Response:	
		ErrorCode
		Clos
		Fisc
		TotA
		TotB
		TotC
		TotD
		TotE
		TotF

	Closure1		Number of the fiscal memory record.
	Closure2		The data returned is for the period with starting record 
			Closure1 and last record Closure2. 

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	Clos		Z-report record number.
	Fisc		Fiscal receipts count.
	TotA		Total (turnover) sum for the corresponding VAT group.
	TotB		Total (turnover) sum for the corresponding VAT group.
	TotC		Total (turnover) sum for the corresponding VAT group.
	TotD		Total (turnover) sum for the corresponding VAT group.
	TotE		Total (turnover) sum for the corresponding VAT group.
	TotF		Total (turnover) sum for the corresponding VAT group.

	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_3.html">CMD_114_3</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about net sums for the Z-report record.

	Data field:	
		Closure1
	Response:		
		ErrorCode
		Clos
		Fisc
		NetA
		NetB
		NetC
		NetD
		NetE
		NetF

	Closure1		Number of the fiscal memory record.

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	Clos		Z-report record number.
	Fisc		Fiscal receipts count.
	NetA		Net sum for the corresponding VAT group.
	NetB		Net sum for the corresponding VAT group.
	NetC		Net sum for the corresponding VAT group.
	NetD		Net sum for the corresponding VAT group.
	NetE		Net sum for the corresponding VAT group.
	NetF		Net sum for the corresponding VAT group.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_4.html">CMD_114_4</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about net sums for the Z-report record.

	Data field:	
		Closure1
		Closure2
	Response:	
		ErrorCode
		Clos
		Fisc
		NetA
		NetB
		NetC
		NetD
		NetE
		NetF

	Closure1		Number of the fiscal memory record.
	Closure2		The data returned is for the period with starting record 
			Closure1 and last record Closure2. 

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	Clos			Z-report record number.
	Fisc			Fiscal receipts count.
	NetA			Net sum for the corresponding VAT group.
	NetB			Net sum for the corresponding VAT group.
	NetC			Net sum for the corresponding VAT group.
	NetD			Net sum for the corresponding VAT group.
	NetE			Net sum for the corresponding VAT group.
	NetF			Net sum for the corresponding VAT group.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_5.html">CMD_114_5</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about VAT sums for the Z-report record.

	Data field:	
		Closure1
	Response:	
		ErrorCode
		Clos
		Fisc
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF

	Closure1		Number of the fiscal memory record.

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	Clos			Z-report record number.
	Fisc			Fiscal receipts count.
	TaxA			VAT sum for the corresponding VAT group.
	TaxB			VAT sum for the corresponding VAT group.
	TaxC			VAT sum for the corresponding VAT group.
	TaxD			VAT sum for the corresponding VAT group.
	TaxE			VAT sum for the corresponding VAT group.
	TaxF			VAT sum for the corresponding VAT group.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_6.html">CMD_114_6</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about VAT sums for the Z-report record.

	Data field:		
		Closure1
		Closure2
	Response:	
		ErrorCode
		Clos
		Fisc
		TaxA
		TaxB
		TaxC
		TaxD
		TaxE
		TaxF

	Closure1		Number of the fiscal memory record.
	Closure2		The data returned is for the period with starting record 
			Closure1 and last record Closure2. 

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	Clos			Z-report record number.
	Fisc			Fiscal receipts count.
	TaxA			VAT sum for the corresponding VAT group.
	TaxB			VAT sum for the corresponding VAT group.
	TaxC			VAT sum for the corresponding VAT group.
	TaxD			VAT sum for the corresponding VAT group.
	TaxE			VAT sum for the corresponding VAT group.
	TaxF			VAT sum for the corresponding VAT group.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_7.html">CMD_114_7</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about VAT sums for the Z-report record.

	Data field:	
		Closure1
	Response:	
		ErrorCode
		Clos
		DecRec
		ResetRec
		HeaderRec
		TechIntervRec
		FMDisc
		PRNDisc

	Closure1		Number of the fiscal memory record.

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	Clos		Z-report record number.
	DecRec		Last (active) decimals and VAT rates record number.
	ResetRec		Last RAM reset number for this Z-report record.
	HeaderRec	Last Header Change number for this Z-report record.
	TechIntervRec	Last Technical Intervention number for this Z-report record.
	FMDisc		Last FM Disconnection number for this Z-report record.
	PRNDisc		Last PRN Disconnection number fot this Z-report record.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_8.html">CMD_114_8</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


Information about decimals and VAT rates record.

	Data field:	
		Closure1
	Response:		
		ErrorCode
		DecimalsCount
		VATEnabled
		PercA	
		PercB
		PercC
		PercD
		PercE
		PercF
		DT

	Closure1		Number of the fiscal memory record.

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	DecimalsCount	Decimals count for this Z-report record.
	VATEnabled	Enabled VAT rates mask - 4 bytes with values '0' or '1', where 
			'1' means "enabled".
	PercA		VAT rate for the corresponding VAT group in percents.
	PercB		VAT rate for the corresponding VAT group in percents.
	PercC		VAT rate for the corresponding VAT group in percents.
	PercD		VAT rate for the corresponding VAT group in percents.
	PercE		VAT rate for the corresponding VAT group in percents.
	PercF		VAT rate for the corresponding VAT group in percents.
	DT		Date and time of the data in format: DD-MM-YY hh:mm:ss.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_9.html">CMD_114_9</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about RAM reset record.

	Data field:	
		Closure1
	Response:		
		ErrorCode
		DT

	Closure1		Number of the fiscal memory record.

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	DT		Date and time of the data in format: DD-MM-YY hh:mm:ss.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_10.html">CMD_114_10</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about HEADER record.

	Data field:	
		Closure1
		Closure2
	Response:	
		ErrorCode
		DT
		HeaderLine

	Closure1		Number of the fiscal memory record.
	Closure2		This parameter selects the required header line (0 to 5).

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	DT		Date and time of the data in format: DD-MM-YY hh:mm:ss.
	HeaderLine	The HEADER line, which is defined.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_114_11.html">CMD_114_11</a></li></td>
					<td><pre>72h (114)	INFORMATION ON THE FISCAL ENTRY OR A FISCAL PERIOD


	Information about Technical Intervention record.

	Data field:	
		Closure1
	Response:	
		ErrorCode[,DT]

	Closure1
		Number of the fiscal memory record.

	ErrorCode	One byte with a value of:
		- 'P'	The data are valid.
		- 'F'	Wrong control sum in the entry. No data available.
		- 'E'	The selected entry is empty. No data available.
	
	
	DT
		Date and time of the data in format: DD-MM-YY hh:mm:ss.
	
The command returns information on different tax groups for each separate entry and or 
a selected period of time. 
Periodic references for longer time periods may take few seconds to process.

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_115_0.html">CMD_115_0</a></li></td>
					<td><pre>73h (115)	PROGRAMMING A GRAPHIC LOGO

	Data field:	
		RowNum
		RowData

	Response:
		None

	RowNum		Shows the line, which is being programmed - a number 
			between 0 and 95
	RowData		Graphic data. Two symbols for each byte of information are 
			entered in the hexadecimal code. The length of the data is 
			up to 72 bytes, and if they are less, an automatic addition 
			of "00" follows.
	
This command offers the option to define a graphic logo with dimensions 
72 x 12 mm (576 x 96 dots) designed by the user themselves. 

The printing of this logo is activated with command 43. It is printed out immediately before 
the HEADER - at the beginning of each fiscal or non-fiscal receipt. In order to define the whole 
logo, the command must be executed 96 times - once for each line. After RESET of memory, 
default logo is active.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_115_1.html">CMD_115_1</a></li></td>
					<td><pre>73h (115)	PROGRAMMING A GRAPHIC LOGO

	Data field:	
		RowNum

	Response:	
		RowData

	RowNum		Shows the line, which is being programmed - a number 
			between 0 and 95
	RowData		Graphic data. Two symbols for each byte of information are 
			entered in the hexadecimal code. The length of the data is 
			up to 72 bytes, and if they are less, an automatic addition of 
			"00" follows.
	
This command offers the option to define a graphic logo with dimensions 
72 x 12 mm (576 x 96 dots) designed by the user themselves. 
The printing of this logo is activated with command 43. It is printed out immediately before 
the HEADER - at the beginning of each fiscal or 
non-fiscal receipt. In order to define the whole logo, the command must be executed 96 times - 
once for each line. After RESET of memory, default logo is active.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_116_0.html">CMD_116_0</a></li></td>
					<td><pre>74h (116)	READ FISCAL MEMORY BLOCK

	Data field:	
		TRGT_ADDR
		BlockLength
	Response:	
		AnswerData

	TRGT_ADDR	Starting address in the fiscal memory in hexadecimal 
			representation (up to 5 hexadecimal digits). 
			From 00000 to 3FFFF for 2 Mbit fiscal memory.
	BlockLength	Block length. From 1 to 64.
	AnswerData	The data, read from the fiscal memory in hexadecimal form 
			(2 symbols for each data byte).

This command offers the option to read directly a block of data from the fiscal memory. It 
is possible to read the whole fiscal memory, sending the command many times with different 
start addresses.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_117_0.html">CMD_117_0</a></li></td>
					<td><pre>75h (117)	REGISTERINg TECHNICAL INTERVENTION

	Data field:	None
	Response:	None

The command is permitted only when the service jumper is placed on the main board of the 
printer. There is place for 150 technical intervention records in the fiscal memory.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_118_0.html">CMD_118_0</a></li></td>
					<td><pre>76h (118)	GET SHIFT LENGTH

	Data field:	
		None
	Response:	
		Seconds

	Seconds	
		The time since the first issued fiscal or refund receipt after Z-report in 
		seconds.

This command is used to check if a Z-report is needed. After the returned value reaches 86400 
(24 hours), the printer will print a warning message at the end of each fiscal or refund receipt.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_121_0.html">CMD_121_0</a></li></td>
					<td><pre>79h (121)	READ CODE MEMORY BLOCK

	Data field:	
		TRGT_ADDR
		BlockLength
	Response:	
		AnswerData

	TRGT_ADDR	Starting address in the code memory in hexadecimal 
			representation (up to 5 hexadecimal digits). 
			From 00000 to 4FFFF.
	BlockLength	Block length. From 1 to 64.
	AnswerData	The data, read from the code memory in hexadecimal 
			form (2 symbols for each data byte).
			

The value (TRGT_ADDR+BlockLength) may not be greater than 30000h 
(for example Address=2FFF0 and Bytes=17 is wrong).

This command offers the option to read directly a block of data from the code memory 
(firmware). It is possible to read the whole code memory, sending the command many times 
with different start addresses.
</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_127_0.html">CMD_127_0</a></li></td>
					<td><pre>7Fh (127)	RAM RESET

	Data field:	None
	Response:	None

The command clears the operational memory of the printer (like the CMOS error). 
After executing it, the clock must be set with command 61, which writes a "CMOS error" 
record in the fiscal memory with this date and time.
The command is permitted only when the service jumper is placed on the main board of 
the printer. There is place for 100 records in the fiscal memory.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_0.html">CMD_120_0</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Electronic journal information.

	Data field: None
	Response:	
		JNum
		LastZNumber
		FirstZNumber
		LWLN
		FreeLines
		TotLines


	JNum		Journal number
	LastZNumber	Last Z-report number of current EJ Card.
	FirstZNumber	First Z-report number of current EJ Card.
	LWLN		Last written line number.
	FreeLines		Free lines count in EJ Card.
	TotLines		Total lines count in EJ Card</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_1.html">CMD_120_1</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 

	Data field:	None
	Response: 
		FP_ANSWER
		ANSWER_TEXT

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_2.html">CMD_120_2</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 
Full journal report (info and lines) for receipt in current period.

	Data field:	
		TRGT_YEAR
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	TRGT_YEAR	DATE TIME in format YY

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_3.html">CMD_120_3</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 
Full journal report (info and lines) for receipt in current period.

	Data field:	
		ZReceipt1
		ZReceipt2
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceipt1		DATE TIME in format YYMMDDhhmm
	ZReceipt2		DATE TIME in format YYMMDDhhmm

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_4.html">CMD_120_4</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 
The period will be from ZReceiptNumber1 and RReceiptNumber2 to ZReceiptNumber3 
and RReceiptNumber4 (with all receipts (R and X) in it).

	Data field:	
		ZReceiptNumber1
		RReceiptNumber2
		ZReceiptNumber3
		RReceiptNumber4
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceiptNumber1		Starting ZReceipt Number
	RReceiptNumber2		Starting RReceipt Number
	ZReceiptNumber3		Ending ZReceipt Number
	RReceiptNumber4		Ending RReceipt Number

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_5.html">CMD_120_5</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 
Only lines for every receipt in current period.

	Data field:
		TRGT_YEAR
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	TRGT_YEAR	DATE TIME in format YY

	FP_ANSWER
			'F'	No journal line found
			'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_6.html">CMD_120_6</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 
Only lines for every receipt in current period.

	Data field:	
		ZReceipt1
		ZReceipt2
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceipt1		DATE TIME in format YYMMDDhhmm
	ZReceipt2		DATE TIME in format YYMMDDhhmm

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_7.html">CMD_120_7</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 
The period will be from ZReceiptNumber1 and RReceiptNumber2 to 
ZReceiptNumber3 and RReceiptNumber4 (with all receipts (R and X) in it).

	Data field:
		ZReceiptNumber1
		RReceiptNumber2
		ZReceiptNumber3
		RReceiptNumber4
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceiptNumber1		Starting ZReceipt Number
	RReceiptNumber2		Starting RReceipt Number
	ZReceiptNumber3		Ending ZReceipt Number
	RReceiptNumber4		Ending RReceipt Number

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_8.html">CMD_120_8</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 
Only info for every receipt in current period.

	Data field:
		TRGT_YEAR
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	TRGT_YEAR	DATE TIME in format YY

	FP_ANSWER
			'F'	No journal line found
			'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_9.html">CMD_120_9</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 
Only info for every receipt in current period.

	Data field:
		ZReceipt1
		ZReceipt2
	Response:
		FP_ANSWER
		ANSWER_TEXT


	ZReceipt1		DATE TIME in format YYMMDDhhmm
	ZReceipt2		DATE TIME in format YYMMDDhhmm

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_10.html">CMD_120_10</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period. 
The period will be from ZReceiptNumber1 and RReceiptNumber2 to ZReceiptNumber3 
and RReceiptNumber4 (with all receipts (R and X) in it).
Only info for every receipt in current period.

	Data field:	
		ZReceiptNumber1
		RReceiptNumber2
		ZReceiptNumber3
		RReceiptNumber4
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceiptNumber1		Starting ZReceipt Number
	RReceiptNumber2		Starting RReceipt Number
	ZReceiptNumber3		Ending ZReceipt Number
	RReceiptNumber4		Ending RReceipt Number

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_11.html">CMD_120_11</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Device print electronic journal starting from the last ZReport, than all journal lines in 
current Z day using normal font size.
Period will be printed, not downloaded !!!
Full journal report (info and lines) for receipt in current period.

	Data field:	None
	Response: 
		FP_ANSWER
		ANSWER_TEXT

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_12.html">CMD_120_12</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
Full journal report (info and lines) for receipt in current period.
Device print electronic journal using normal font size.

	Data field:
		ZReceipt1
		ZReceipt2
	Response:
		FP_ANSWER
		ANSWER_TEXT


	ZReceipt1		DATE TIME in format YYMMDDhhmm
	ZReceipt2		DATE TIME in format YYMMDDhhmm

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_13.html">CMD_120_13</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
Full journal report (info and lines) for receipt in current period.
Device print electronic journal using normal font size.
The period will be from ZReceiptNumber1 and RReceiptNumber2 to 
ZReceiptNumber3 and RReceiptNumber4 (with all receipts (R and X) in it).

	Data field:	
		ZReceiptNumber1
		RReceiptNumber2
		ZReceiptNumber3
		RReceiptNumber4
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceiptNumber1		Starting ZReceipt Number
	RReceiptNumber2		Starting RReceipt Number
	ZReceiptNumber3		Ending ZReceipt Number
	RReceiptNumber4		Ending RReceipt Number

	FP_ANSWER
				'F'	No journal line found
				'P'	Journal line successfully read
	ANSWER_TEXT		The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_14.html">CMD_120_14</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
Only lines for every receipt in current period.
Device print electronic journal using normal font size.

	Data field:	
		ZReceipt1
		ZReceipt2
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceipt1		DATE TIME in format YYMMDDhhmm
	ZReceipt2		DATE TIME in format YYMMDDhhmm

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_15.html">CMD_120_15</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
The period will be from ZReceiptNumber1 and RReceiptNumber2 to 
ZReceiptNumber3 and RReceiptNumber4 (with all receipts (R and X) in it).

Only lines for every receipt in current period.
Device print electronic journal using normal font size.

	Data field:	
		ZReceiptNumber1
		RReceiptNumber2
		ZReceiptNumber3
		RReceiptNumber4
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceiptNumber1		Starting ZReceipt Number
	RReceiptNumber2		Starting RReceipt Number
	ZReceiptNumber3		Ending ZReceipt Number
	RReceiptNumber4		Ending RReceipt Number

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_16.html">CMD_120_16</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
The period will be from ZReceiptNumber1 and RReceiptNumber2 to 
ZReceiptNumber3 and RReceiptNumber4 (with all receipts (R and X) in it).

Only info for every receipt in current period.
Device print electronic journal using normal font size.

	Data field:
		ZReceipt1
		ZReceipt2
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceipt1		DATE TIME in format YYMMDDhhmm
	ZReceipt2		DATE TIME in format YYMMDDhhmm

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_17.html">CMD_120_17</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
The period will be from ZReceiptNumber1 and RReceiptNumber2 to 
ZReceiptNumber3 and RReceiptNumber4 (with all receipts (R and X) in it).

Only info for every receipt in current period.
Device print electronic journal using normal font size.

	Data field:	
		ZReceiptNumber1
		RReceiptNumber2
		ZReceiptNumber3
		RReceiptNumber4
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceiptNumber1		Starting ZReceipt Number
	RReceiptNumber2		Starting RReceipt Number
	ZReceiptNumber3		Ending ZReceipt Number
	RReceiptNumber4		Ending RReceipt Number

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_18.html">CMD_120_18</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Device print electronic journal starting from the last ZReport, than all journal lines in 
current Z day using normal font size.

Period will be printed, not downloaded !!!

Full journal report (info and lines) for receipt in current period.
Print journal using half-height font size.

	Data field:	None
	Response: 
		FP_ANSWER
		ANSWER_TEXT

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_19.html">CMD_120_19</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
Full journal report (info and lines) for receipt in current period.
Print journal using half-height font size.

	Data field:
		ZReceipt1
		ZReceipt2
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceipt1		DATE TIME in format YYMMDDhhmm
	ZReceipt2		DATE TIME in format YYMMDDhhmm

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_20.html">CMD_120_20</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
Full journal report (info and lines) for receipt in current period.
Print journal using half-height font size.
The period will be from ZReceiptNumber1 and RReceiptNumber2 to 
ZReceiptNumber3 and RReceiptNumber4 (with all receipts (R and X) in it).

	Data field:	
		ZReceiptNumber1
		RReceiptNumber2
		ZReceiptNumber3
		RReceiptNumber4
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceiptNumber1		Starting ZReceipt Number
	RReceiptNumber2		Starting RReceipt Number
	ZReceiptNumber3		Ending ZReceipt Number
	RReceiptNumber4		Ending RReceipt Number

	FP_ANSWER
				'F'	No journal line found
				'P'	Journal line successfully read
	ANSWER_TEXT		The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_21.html">CMD_120_21</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
Only lines for every receipt in current period.
Print journal using half-height font size.

	Data field:	
		ZReceipt1
		ZReceipt2
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceipt1		DATE TIME in format YYMMDDhhmm
	ZReceipt2		DATE TIME in format YYMMDDhhmm

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_22.html">CMD_120_22</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
The period will be from ZReceiptNumber1 and RReceiptNumber2 to 
ZReceiptNumber3 and RReceiptNumber4 (with all receipts (R and X) in it).

Only lines for every receipt in current period.
Print journal using half-height font size.

	Data field:	
		ZReceiptNumber1
		RReceiptNumber2
		ZReceiptNumber3
		RReceiptNumber4
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceiptNumber1		Starting ZReceipt Number
	RReceiptNumber2		Starting RReceipt Number
	ZReceiptNumber3		Ending ZReceipt Number
	RReceiptNumber4		Ending RReceipt Number

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.

</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_23.html">CMD_120_23</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
The period will be from ZReceiptNumber1 and RReceiptNumber2 to 
ZReceiptNumber3 and RReceiptNumber4 (with all receipts (R and X) in it).

Only info for every receipt in current period.
Print journal using half-height font size.

	Data field:	
		ZReceipt1
		ZReceipt2
	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceipt1		DATE TIME in format YYMMDDhhmm
	ZReceipt2		DATE TIME in format YYMMDDhhmm

	FP_ANSWER
		'F'	No journal line found
		'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_24.html">CMD_120_24</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get first journal line in period but period will be printed, not downloaded. 
The period will be from ZReceiptNumber1 and RReceiptNumber2 to 
ZReceiptNumber3 and RReceiptNumber4 (with all receipts (R and X) in it).

Only info for every receipt in current period.
Print journal using half-height font size.

	Data field:	
		ZReceiptNumber1
		RReceiptNumber2
		ZReceiptNumber3
		RReceiptNumber4

	Response: 
		FP_ANSWER
		ANSWER_TEXT


	ZReceiptNumber1		Starting ZReceipt Number
	RReceiptNumber2		Starting RReceipt Number
	ZReceiptNumber3		Ending ZReceipt Number
	RReceiptNumber4		Ending RReceipt Number

	FP_ANSWER
				'F'	No journal line found
				'P'	Journal line successfully read
	ANSWER_TEXT		The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_25.html">CMD_120_25</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Get next journal line.

	Data field:	
		None
	Response:	
		FP_ANSWER
		ANSWER_TEXT

	FP_ANSWER
			'F'	No journal line found
			'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_26.html">CMD_120_26</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Continue of command:
	120_11
	120_12
	120_13
	120_14
	120_15
	120_16
	120_17
	120_18
	120_19
	120_20
	120_21
	120_22
	120_23
	120_24
(starting with the first non-printed receipt) using normal font size.






	Data field:		None
	Response:		FP_ANSWER,ANSWER_TEXT

	FP_ANSWER
			'F'	No journal line found
			'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/CMD_120_27.html">CMD_120_27</a></li></td>
					<td><pre>78h (120)	ELECTRONIC JOURNAL SUPPORT

Continue of command:
	120_11
	120_12
	120_13
	120_14
	120_15
	120_16
	120_17
	120_18
	120_19
	120_20
	120_21
	120_22
	120_23
	120_24
(starting with the first non-printed receipt) using half-height font size.


	Data field:	
		None
	Response:	
		FP_ANSWER
		ANSWER_TEXT

	FP_ANSWER
			'F'	No journal line found
			'P'	Journal line successfully read
	ANSWER_TEXT	The journal line, ready to be stored in a file.</pre></td>
				</tr>
				<tr>
					<td><li><a href="lib/'-'.html">'-'</a></li></td>
					<td><pre>29h (41)	SET MEMORY SWITCHES

	Data field:	None
	Response:	None


	The command writes to flash memory the switches value, graphics logo, barcode height, print 
	darkness and default drawer pulse length. After RAM reset they are restored with the saved values.
	If the switches parameter is not present, then the old switches are kept.

</pre></td>
				</tr>
			</table>
			</div>
		</td>
	</tr>
</table>
<center>&copy; Copyright <a href="http://www.datecs.bg">DATECS</a> 2010 &reg;</center>
</body>
</html>
