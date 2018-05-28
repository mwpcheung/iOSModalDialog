-(void)operation:(ISDialogOperation*)dialogOpt selectedButton:(ISDialogButton*)button
{
	DebugPrint(@"ModalDialog button click event title %@ message %@ button title %@  actionType %d", dialogOpt.dialog.title,
			   dialogOpt.dialog.message, button.title, button.actionType);
}
// 模态的MessageBox 跨进程操作，线程会被阻塞死.
-(NSString*)doModalDialog:(NSString*)title message:(NSString*)message titles:(NSArray *)titles
{

    ISDialog *__dialogue =  [[NSClassFromString(@"ISDialog") alloc] init];
	__dialogue.shouldDisplayAsTopMost = true;
	__dialogue.shouldPendInSetupIfNotAllowed = true;
	[__dialogue setMessage:message];
	[__dialogue setTitle:title];
    NSMutableArray * btnArray = [[NSMutableArray alloc] init];
    for (int i = 0 ; i < [titles count]; i++){
		ISDialogButton *button = [NSClassFromString(@"ISDialogButton") buttonWithTitle:titles[i]];
		button.actionType = i;
        [btnArray addObject:button];
    }
    if ([btnArray count] > 0){
		[__dialogue setButtons:btnArray];
		[__dialogue setDefaultButtonIndex:1];
		[__dialogue setExpectsResponse:true];
		[__dialogue setOneButtonPerLine:true];
    }
    ISDialogOperation* dialog = [[NSClassFromString(@"ISDialogOperation") alloc] init];
	dialog.delegate = self;
	dialog.dialog = __dialogue;
	[dialog run];
    ISDialogButton * sbtn = [dialog selectedButton];
	NSString* selectedTitle = @"";

	if (sbtn){
		DebugPrint(@"selected button %p action %d title %@", sbtn, sbtn.actionType, sbtn.title);
		selectedTitle = [[sbtn title] mutableCopy];
	}else{
		DebugPrint(@"selected button is null ");
	}
	for (ISDialogButton* btn in btnArray){
		[btn release];
	}
	[btnArray removeAllObjects];
	[btnArray release];
	[__dialogue release];
	[dialog release];
	return selectedTitle;
}

///
NSString* selectedText = [self doModalDialog:@"this is title"message: @"this is message" titles:@[@"button1", @"button2"];
// after dialog run over
DebugPrint(@"selected text is %@", selectedText);
// 
