/* Quartus Prime Version 21.1.0 Build 842 10/21/2021 SJ Standard Edition */
JedecChain;
	FileRevision(JESD32A);
	DefaultMfr(6E);

	P ActionCode(Cfg)
		Device PartName(10CL025YU256) Path("C:/intelFPGA/Cyclone_X/Starter_template/output_files/") File("simple_blinky.sof") MfrSpec(OpMask(1));
	P ActionCode(Ign)
		Device PartName(VTAP10) MfrSpec(OpMask(0));

ChainEnd;

AlteraBegin;
	ChainType(JTAG);
AlteraEnd;
