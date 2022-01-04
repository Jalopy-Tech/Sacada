function Component()
{
    // default constructor
}

Component.prototype.createOperations = function()
{
    // call default implementation to actually install README.txt!
    component.createOperations();

    if (systemInfo.productType === "windows") {
        component.addOperation("CreateShortcut",
			"@TargetDir@/sacada/Sacada.exe",
			"@StartMenuDir@/Sacada.lnk",
           		"workingDirectory=@TargetDir@/sacada");
			
	component.addOperation("CreateShortcut", 
			"@TargetDir@/sacada/Sacada.exe",
			"@DesktopDir@/Sacada.lnk",
			"workingDirectory=@TargetDir@/sacada");
    }
	
	
}


