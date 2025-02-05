/*scalaVersion := "2.13.10"
scalacOptions += "-language:higherKinds"
//addCompilerPlugin("org.typelevel" %% "kind-projector" % "0.10.3" cross CrossVersion.binary)
addCompilerPlugin("edu.berkeley.cs" % "chisel3-plugin" % "3.6.0" cross CrossVersion.full)
libraryDependencies ++= Seq(
  "edu.berkeley.cs" %% "chisel3" % "3.6.0",
  "edu.berkeley.cs" %% "chiseltest" % "6.0.0" % "test",
  "edu.berkeley.cs" %% "chisel-iotesters" % "2.5.1" % "test"
  // https://mvnrepository.com/artifact/org.chipsalliance/chisel-plugin
libraryDependencies += "org.chipsalliance" %% "chisel-plugin" % "6.0.0"

)
turbo := true
//useSuperShell := false
scalacOptions ++= Seq(
  "-deprecation",
  "-encoding", "UTF-8",
  "-feature",
  "-unchecked",
  "-Xsource:2.13.10",
  "-language:reflectiveCalls"
)*/

// ...

// build.sbt
scalaVersion := "2.13.12"
val chiselVersion = "6.0.0"
addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full)
libraryDependencies += "org.chipsalliance" %% "chisel" % chiselVersion
// https://mvnrepository.com/artifact/edu.berkeley.cs/chiseltest
libraryDependencies += "edu.berkeley.cs" %% "chiseltest" % "6.0.0"
// https://mvnrepository.com/artifact/org.scalatest/scalatest
libraryDependencies += "org.scalatest" %% "scalatest" % "3.2.18" % Test


turbo := true
scalacOptions ++= Seq(
  "-deprecation",
  "-encoding", "UTF-8",
  "-feature",
  "-unchecked",
  "-Xsource:2.13.12",
  "-language:reflectiveCalls"
)



/*lazy val root = (project in file(".")).settings(
  name := "my-project",
  version := "1.0",
  mainClass := "Main"
) */

// ...

// // See README.md for license details.

// ThisBuild / scalaVersion     := "2.13.12"
// ThisBuild / version          := "0.1.0"
// ThisBuild / organization     := "%ORGANIZATION%"

// Test / logBuffered := false
// Test / parallelExecution := false

// val chiselVersion = "5.1.0"

// lazy val root = (project in file("."))
//   .settings(
//     name := "snn-accel",
//     libraryDependencies ++= Seq(
//       "org.chipsalliance" %% "chisel" % chiselVersion,
//       //"edu.berkeley.cs" %% "chiseltest" % "5.0.2" % "test",
//       "edu.berkeley.cs" %% "chiseltest" % "5.0.2",
//       //"edu.berkeley.cs" %% "firrtl" % "5.0.0",
//       "com.lihaoyi" %% "ujson" % "0.9.6"
//     ),
//     scalacOptions ++= Seq(
//       "-language:reflectiveCalls",
//       "-deprecation",
//       "-feature",
//       "-Xcheckinit",
//       "-Ymacro-annotations",
//     ),
//     addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
//   )


// ....

// scalaVersion := "2.12.12"
// scalacOptions += "-language:higherKinds"
// addCompilerPlugin("org.typelevel" %% "kind-projector" % "0.10.3" cross CrossVersion.binary)

// scalacOptions += "-Ydelambdafy:inline"
// turbo := true
// useSuperShell := false
// scalacOptions ++= Seq(
//   "-deprecation",
//   "-encoding", "UTF-8",
//   "-feature",
//   "-unchecked",
//   "-Xfatal-warnings",
//   "-Xsource:2.11",
//   "-language:reflectiveCalls"
// )
// val chiselVersion = "3.4.2"
// addCompilerPlugin("edu.berkeley.cs" %% "chisel3-plugin" % chiselVersion cross CrossVersion.full)
// libraryDependencies += "edu.berkeley.cs" %% "chisel3" % chiselVersion
