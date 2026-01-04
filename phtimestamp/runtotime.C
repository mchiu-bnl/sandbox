void runtotime()
{
  gSystem->Load("libpdbcalBase.so");
  gSystem->Load("libPgCal.so");

  RunToTime *runtotime = new RunToTime();
  PHTimeStamp *begintime = runtotime->getBeginTime( run_number );
  PHTimeStamp *endtime = runtotime->getEndTime( run_number );
  time_t meantime = begintime->getTics()/2 + endtime->getTics()/2;
  begintime->Print();
  endtime->Print();

  delete begintime;
  delete endtime;

}
