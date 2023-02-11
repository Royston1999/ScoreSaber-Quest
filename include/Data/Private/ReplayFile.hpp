#pragma once

#include <stdlib.h>
#include <string>
#include <vector>

#include "UnityEngine/Quaternion.hpp"
#include "UnityEngine/Vector3.hpp"

using namespace std;

namespace ScoreSaber::Data::Private
{
    struct Pointers
    {
        Pointers();
        Pointers(int metadata, int poseKeyframes, int heightKeyframes, int noteKeyframes, int scoreKeyframes, int comboKeyframes, int multiplierKeyframes, int energyKeyframes, int fpsKeyframes);
        int metadata;
        int poseKeyframes;
        int heightKeyframes;
        int noteKeyframes;
        int scoreKeyframes;
        int comboKeyframes;
        int multiplierKeyframes;
        int energyKeyframes;
        int fpsKeyframes;
    };

    struct VRPosition
    {
        VRPosition();
        VRPosition(float X, float Y, float Z);
        VRPosition(UnityEngine::Vector3 vector);
        float X;
        float Y;
        float Z;
    };

    struct VRRotation
    {
        VRRotation();
        VRRotation(float X, float Y, float Z, float W);
        VRRotation(UnityEngine::Quaternion quaternion);
        float X;
        float Y;
        float Z;
        float W;
    };

    struct VRPose
    {
        VRPose();
        VRPose(VRPosition Position, VRRotation Rotation);
        VRPosition Position;
        VRRotation Rotation;
    };

    struct ScoreEvent
    {
        ScoreEvent();
        ScoreEvent(int Score, float Time);
        int Score;
        float Time;
    };

    struct ComboEvent
    {
        ComboEvent();
        ComboEvent(int Combo, float Time);
        int Combo;
        float Time;
    };

    enum NoteEventType
    {
        None,
        GoodCut,
        BadCut,
        Miss,
        Bomb
    };

    struct NoteID
    {
        NoteID();
        NoteID(float Time, int LineLayer, int LineIndex, int ColorType, int CutDirection);
        float Time;
        int LineLayer;
        int LineIndex;
        int ColorType;
        int CutDirection;
    };

    struct EnergyEvent
    {
        EnergyEvent();
        EnergyEvent(float Energy, float Time);
        float Energy;
        float Time;
    };

    struct HeightEvent
    {
        HeightEvent();
        HeightEvent(float Height, float Time);
        float Height;
        float Time;
    };

    struct MultiplierEvent
    {
        MultiplierEvent();
        MultiplierEvent(int Multiplier, float NextMultiplierProgress, float Time);
        int Multiplier;
        float NextMultiplierProgress;
        float Time;
    };

    struct VRPoseGroup
    {
        VRPoseGroup();
        VRPoseGroup(VRPose Head, VRPose Left, VRPose Right, int FPS, float Time);
        VRPose Head;
        VRPose Left;
        VRPose Right;
        int FPS;
        float Time;
    };

    struct Metadata
    {
        Metadata();
        Metadata(string Version, string LevelID, int Difficulty, string Characteristic, string Environment, vector<string> Modifiers, float NoteSpawnOffset,
                 bool LeftHanded, float InitialHeight, float RoomRotation, VRPosition RoomCenter, float FailTime);
        string Version;
        string LevelID;
        int Difficulty;
        string Characteristic;
        string Environment;
        vector<string> Modifiers;
        float NoteSpawnOffset;
        bool LeftHanded;
        float InitialHeight;
        float RoomRotation;
        VRPosition RoomCenter;
        float FailTime;
    };

    struct NoteEvent
    {
        NoteEvent();
        NoteEvent(NoteID TheNoteID, NoteEventType EventType, VRPosition CutPoint, VRPosition CutNormal, VRPosition SaberDirection, int SaberType, bool DirectionOK,
                  float SaberSpeed, float CutAngle, float CutDistanceToCenter, float CutDirectionDeviation, float BeforeCutRating, float AfterCutRating,
                  float Time, float UnityTimescale, float TimeSyncTimescale);
        NoteID TheNoteID;
        NoteEventType EventType;
        VRPosition CutPoint;
        VRPosition CutNormal;
        VRPosition SaberDirection;
        int SaberType;
        bool DirectionOK;
        float SaberSpeed;
        float CutAngle;
        float CutDistanceToCenter;
        float CutDirectionDeviation;
        float BeforeCutRating;
        float AfterCutRating;
        float Time;
        float UnityTimescale;
        float TimeSyncTimescale;
    };

    struct ReplayFile
    {
        ReplayFile();
        ReplayFile(std::shared_ptr<Metadata> metadata, vector<VRPoseGroup> poseKeyframes, vector<HeightEvent> heightKeyframes, vector<NoteEvent> noteKeyframes,
                   vector<ScoreEvent> scoreKeyframes, vector<ComboEvent> comboKeyframes, vector<MultiplierEvent> multiplierKeyframes,
                   vector<EnergyEvent> energyKeyframes);
        shared_ptr<Metadata> metadata;
        vector<VRPoseGroup> poseKeyframes;
        vector<HeightEvent> heightKeyframes;
        vector<NoteEvent> noteKeyframes;
        vector<ScoreEvent> scoreKeyframes;
        vector<ComboEvent> comboKeyframes;
        vector<MultiplierEvent> multiplierKeyframes;
        vector<EnergyEvent> energyKeyframes;
    };
    UnityEngine::Vector3 VRVector3(VRPosition pose);
    UnityEngine::Quaternion VRQuaternion(VRRotation rotation);

} // namespace ScoreSaber::Data::Private
