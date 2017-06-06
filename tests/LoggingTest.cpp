int main(int argc, char **argv)
{
	CLog Log("test.log"); // Add auto ".log" extension?
	
	Log.Write("Well");
	
	Log.Info("This thing is working");
	
	Log.Debug("Testing");
	
	Log.Warning("Something isn't right");
	
	Log.Error("Unhandled exception");
	
	Log.FatalError("Cannot find my shoes...");
	
	Log.TraceInit("Subsystem A");
	
	Log.TraceShutdown("Subsystem A");
	
	return EXIT_SUCCESS;
};